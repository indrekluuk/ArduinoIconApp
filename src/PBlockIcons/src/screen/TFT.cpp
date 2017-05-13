//
// Created by indrek on 26.03.2017.
//

#include "TFT.h"
#include "Font.h"
#include "Arduino.h"






void TFT::startTextFillBox(uint16_t x, uint16_t y, uint8_t w, uint8_t h, uint8_t cursorX, uint8_t cursorY) {
  setCursor(x+cursorX, y+cursorY);

  textFillBoxX = x;
  textFillBoxY = y;
  textFillBoxW = w;
  textFillBoxH = h;

  if (cursorY > 0) {
    fillRect(x, y, w, cursorY, textbgcolor);
  }
  if (cursorX > 0) {
    fillRect(x, cursor_y, cursorX, textsize * 8, textbgcolor);
  }
}


void TFT::finishTextFillBox() {
  int16_t boxX2 = textFillBoxX + textFillBoxW;
  int16_t boxY2 = textFillBoxY + textFillBoxH;
  uint8_t textHeight = textsize * (uint8_t)8;

  if (cursor_x < boxX2) {
    fillRect(cursor_x, cursor_y, boxX2 - cursor_x, textHeight, textbgcolor);
  }
  if (cursor_y < boxY2) {
    int16_t y = cursor_y + textHeight;
    fillRect(textFillBoxX, y, textFillBoxW, boxY2 - y, textbgcolor);
  }
}



size_t TFT::write(uint8_t c) {
  if(c == '\n') {
  } else if(c == '\r') {
  } else {

    if(!_cp437 && (c >= 176)) c++; // Handle 'classic' charset behavior

    uint8_t glyph[5];
    for(int8_t i=0; i<5; i++ ) {
      glyph[i] = pgm_read_byte(fontBitmap+(c*5)+i);
    }
    RgbColor fgColor(textcolor);
    RgbColor bgColor(textbgcolor);

    setAddrWindow(cursor_x, cursor_y, cursor_x + (6 * textsize)-1, cursor_y + (8 * textsize)-1);
    CS_ACTIVE;
    WriteCmd(_MW);
    CD_DATA;

    uint8_t rowMask = 0x1;
    for (uint8_t cRow = 0; cRow < 8; cRow++) {
      for (uint8_t s = 0; s < textsize; s++) {
        for (uint8_t cCol=0; cCol < 5; cCol++) {
          writeColorN(glyph[cCol] & rowMask ? fgColor : bgColor, textsize);
        }
        writeColorN(bgColor, textsize);
      }
      rowMask <<= 1;
    }

    CS_IDLE;

    cursor_x += textsize * 6;
  }
  return 1;
}






void TFT::drawIcon(uint16_t x, uint16_t y, Icon & icon, IconColor iconColor, uint8_t w, uint8_t h, uint8_t dx, uint8_t dy, uint8_t scaleW, uint8_t scaleH) {
  setAddrWindow(x, y, x + w - 1, y + h - 1);
  CS_ACTIVE;
  WriteCmd(_MW);
  CD_DATA;

  RgbColor fgColor = iconColor.getForegroundColor();
  RgbColor bgColor = iconColor.getBackgroundColor();

  uint8_t bitmapW = icon.BITMAP_WIDTH * scaleW;
  uint8_t bitmapH = icon.BITMAP_HEIGHT * scaleH;
  uint8_t bitmapX = ((w - bitmapW) >> 1) + dx;
  uint8_t bitmapX2 = bitmapX + bitmapW;
  uint8_t bitmapY = ((h - bitmapH) >> 1) + dy;
  uint8_t bitmapY2 = bitmapY + bitmapH;


  // background lines before icon
  if (bitmapY > 0) {
    writeColorN(bgColor, bitmapY * w);
  }

  if (iconColor.hasBorder) {
    RgbColor bTopColor = iconColor.hasBorder3d ? RgbColor(COLOR_WHITE) : iconColor.getBorderColor();
    RgbColor bBottomColor = iconColor.hasBorder3d ? RgbColor(COLOR_BLACK) : iconColor.getBorderColor();
    // draw icon with border
    uint16_t prvRow = 0;
    uint16_t curRow = 0;
    uint16_t nxtRow = icon.getRow(0);
    for (uint8_t bRow = 0; bRow < icon.BITMAP_HEIGHT; bRow++) {
      curRow = nxtRow;
      for (uint8_t s = 0; s<scaleH; s++) {
        if (s == scaleH-1) {
          nxtRow = (bRow == icon.BITMAP_HEIGHT - 1) ? (uint16_t)0 : icon.getRow(bRow + (uint8_t)1);
        }
        if (bitmapX > 0) {
          writeColorN(bgColor, bitmapX);
        }

        write8bitmapWithBorder(
            fgColor,
            bgColor,
            bTopColor,
            bBottomColor,
            prvRow,
            curRow,
            nxtRow,
            scaleW);

        if (bitmapX2 < w) {
          writeColorN(bgColor, w - bitmapX2);
        }
        prvRow = curRow;
      }
    }


  } else {
    // draw icon without border
    for (uint8_t bRow = 0; bRow < icon.BITMAP_HEIGHT; bRow++) {
      uint16_t row = icon.getRow(bRow);
      for (uint8_t s = 0; s < scaleH; s++) {
        if (bitmapX > 0) {
          writeColorN(bgColor, bitmapX);
        }
        write8bitmap(
            fgColor,
            bgColor,
            row,
            scaleW);
        if (bitmapX2 < w) {
          writeColorN(bgColor, w - bitmapX2);
        }
      }
    }
  }

  // background lines after icon
  if (bitmapY2 < h) {
    writeColorN(bgColor, (h - bitmapY2) * w);
  }

  CS_IDLE;
}








void TFT::write8bitmap(
    RgbColor color,
    RgbColor bgColor,
    uint16_t bitmap,
    uint8_t scale
) {
  uint16_t mask = 0x8000;
  while (mask) {
    if (bitmap & mask) {
      writeColorN(color, scale);
    } else {
      writeColorN(bgColor, scale);
    }
    mask >>= 1;
  }
}





void TFT::write8bitmapWithBorder(
    RgbColor color,
    RgbColor bgColor,
    RgbColor bTopColor,
    RgbColor bBottomColor,
    uint16_t prvBitmap,
    uint16_t curBitmap,
    uint16_t nxtBitmap,
    uint8_t scale
) {
  uint16_t mask = 0x8000;
  uint16_t nextMask;

  uint16_t isPrevious = 0;
  while (mask) {
    nextMask = mask >> 1;
    uint16_t isCurrent = curBitmap & mask;

    if (isCurrent) {
      if ((prvBitmap & mask) != mask) {
        writeColorN(bTopColor, scale);
      } else if ((nxtBitmap & mask) != mask) {
        writeColorN(bBottomColor, scale);
      } else {

        uint16_t isNext = curBitmap & nextMask;
        if (isPrevious && isNext) {
          writeColorN(color, scale);
        } else if (isPrevious) {
          writeColorN(color, scale - (uint16_t)1);
          writeColorN(bBottomColor, 1);
        } else if (isNext) {
          writeColorN(bTopColor, 1);
          writeColorN(color, scale - (uint16_t)1);
        } else {
          writeColorN(bTopColor, 1);
          if (scale > 1) {
            writeColorN(color, scale - (uint16_t)2);
            writeColorN(bBottomColor, 1);
          }
        }

      }
    } else {
      writeColorN(bgColor, scale);
    }

    isPrevious = isCurrent;
    mask = nextMask;
  }
}



void TFT::writeColorN(RgbColor color, uint16_t n) {
  while (n) {
    write8(color.colorH);
    write8(color.colorL);
    n--;
  }
}


void TFT::drawPalette(uint16_t x, uint16_t y, uint16_t w, uint16_t h, float V) {
  setAddrWindow(x, y, x + w - 1, y + h - 1);
  CS_ACTIVE;
  WriteCmd(_MW);
  CD_DATA;

  float Hsection = (h-1) / 6.0f;
  uint16_t H1 = Hsection * 1;
  uint16_t H2 = Hsection * 2;
  uint16_t H3 = Hsection * 3;
  uint16_t H4 = Hsection * 4;
  uint16_t H5 = Hsection * 5;
  float dS = (1.0f / (w - 1.0f)) * V;

  for (uint16_t H=0; H<h; H++) {
    float Hdiv = (H / Hsection);
    uint16_t HIntDiv = (uint16_t)Hdiv;
    float Hmod = HIntDiv % 2 + (Hdiv - (HIntDiv + (uint16_t)1));
    float Hmult = (1.0f - abs(Hmod));

    float S = 0;
    for (uint16_t Scnt=0; Scnt<w; Scnt++) {
      S += dS;
      if (S > 1) S = 1;
      float X = S * Hmult;

      float Rp;
      float Gp;
      float Bp;

      if (H < H1) {
        Rp = S;
        Gp = X;
        Bp = 0;
      } else if (H < H2) {
        Rp = X;
        Gp = S;
        Bp = 0;
      } else if (H < H3) {
        Rp = 0;
        Gp = S;
        Bp = X;
      } else if (H < H4) {
        Rp = 0;
        Gp = X;
        Bp = S;
      } else if (H < H5) {
        Rp = X;
        Gp = 0;
        Bp = S;
      } else {
        Rp = S;
        Gp = 0;
        Bp = X;
      }

      float m = V - S;
      if (m < 0) m = 0;
      uint16_t R = (Rp + m) * (uint16_t)31;
      uint16_t G = (Gp + m) * (uint16_t)63;
      uint16_t B = (Bp + m) * (uint16_t)31;

      uint16_t RGB = ((R << 11) & 0xF800)
                     | ((G << 5) & 0x07E0)
                     | (B & 0x001F);

      write8(((uint8_t *)(&RGB))[1]);
      write8(((uint8_t *)(&RGB))[0]);
    }
  }

  CS_IDLE;
}












