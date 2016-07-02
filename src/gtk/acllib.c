//
// Created by zhenghu on 16-7-2.
//
#include "../common/acllib.h"
int Setup() {

}


void initWindow(const char title[], int left, int top, int width, int height) {

}
void msgBox(const char title[], const char text[], int flag) {

}

void registerKeyboardEvent(KeyboardEventCallback callback) {

}
void registerCharEvent(CharEventCallback callback) {

}
void registerMouseEvent(MouseEventCallback callback) { }
void registerTimerEvent(TimerEventCallback callback) { }

void startTimer(int timerID, int timeinterval) { }
void cancelTimer(int timerID) { }

// Sound
void loadSound(const char *fileName, ACL_Sound *pSound) { }
void playSound(ACL_Sound soundID, int repeat) { }
void stopSound(ACL_Sound soundID) { }

// Paint
void beginPaint() {

}
void endPaint() { }
void clearDevice(void) { }
int getWidth() { }
int getHeight() { }

// Pen
void setPenColor(ACL_Color color) { }
void setPenWidth(int width) { }
void setPenStyle(ACL_Pen_Style style) { }

// Brush
void setBrushColor(ACL_Color color) { }
void setBrushStyle(ACL_Brush_Style style) { }

// Text
void setTextColor(ACL_Color color) { }
void setTextBkColor(ACL_Color color) { }
void setTextSize(int size) { }
void setTextFont(const char *pFontName) { }

void paintText(int x, int y, const char *pStr) { }

void setCaretSize(int w, int h) { }
void setCaretPos(int x, int y) { }
void showCaret() { }
void hideCaret() { }

// Pixel
void putPixel(int x, int y, ACL_Color color) { }
ACL_Color getPixel(int x, int y) { }

// the Point
int getX(void) { }
int getY(void) { }
void moveTo(int x, int y) { }
void moveRel(int dx, int dy) { }

// Lines and Curves
void arc(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nXStartArc, int nYStartArc, int nXEndArc, int nYEndArc) { }
void line(int x0, int y0, int x1, int y1) { }
void lineTo(int nXEnd, int nYEnd) { }
void lineRel(int dx, int dy) { }
void polyBezier(const POINT *lppt, int cPoints) { }
void polyLine(const POINT *lppt, int cPoints) { }

// Filled Shapes
void chrod(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2) { }
void ellipse(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) { }
void pie(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2) { }
void polygon(const POINT *lpPoints, int nCount) { }
void rectangle(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) { }
void roundrect(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nWidth, int nHeight) { }

// Image
void loadImage(const char *pImageFileName, ACL_Image *pImage) { }
void freeImage(ACL_Image *pImage) { }

void putImage(ACL_Image *pImage, int x, int y) { }
void putImageScale(ACL_Image *pImage, int x, int y, int width, int height) { }
void putImageTransparent(ACL_Image *pImage, int x, int y, int width, int height, ACL_Color bkColor) { }


void initConsole(void) { }