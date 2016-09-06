//
// Created by Colliot on 2016/9/6.
//

#ifndef PROJECT_PAINTAREA_H
#define PROJECT_PAINTAREA_H


#include <acllib.h>

#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <QPen>
#include <QBrush>
#include <QRect>
#include <QMouseEvent>
#include <deque>
#include <map>
#include "../verdigris/src/wobjectimpl.h"
#include "../verdigris/src/wobjectdefs.h"
#include <QtWidgets/QMessageBox>

#include "timer.h"

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
};

///
struct Line {
  int startX, startY;
  int endX, endY;
  Line(int startX, int startY, int endX, int endY) : startX(startX), startY(startY), endX(endX), endY(endY) {}
};


enum class ShapeType {
  LINE, ELLIPSE, RECTANGLE
};

struct DrawingTuple {
  // The pen
  ACL_Color penColor = BLACK;
  int penWidth = 1;
  int penStyle = PEN_STYLE_SOLID;
  // The brush
  ACL_Color brushColor = BLACK;
  int brushStyle = BRUSH_STYLE_SOLID;
};

class AclGlobalWidget: public QWidget {
  W_OBJECT(AclGlobalWidget)
 private:
  QImage image;
  DrawingTuple drawingTuple;
  QPen qPen;
  QBrush qBrush;
  std::string title;
  Point *currentPoint;
  QTimer *timer;
  std::deque<Line> lines;
  std::deque<QRect> ellipses;
  std::map<int, IntTimer *> timers;
  TimerEventCallback timerEventCallback;
 protected:
  void paintEvent(QPaintEvent *event);
  void resizeEvent(QResizeEvent *event);
  void mousePressEvent(QMouseEvent *event);
  void resizeImage(QImage *image, const QSize &newSize);
  void timerListener(int timerId);
  W_SLOT(timerListener)
 public:
  AclGlobalWidget();
  ~AclGlobalWidget();

  //
  int getX(void);
  int getY(void);
  void moveTo(int x, int y);
  void moveRel(int dx, int dy);
  ///
  void addLine(int startX, int startY, int endX, int endY);
  void addLineTo(int endX, int endY);
  void lineRel(int dx, int dy);
  void polyBezier(const POINT *lppt, int cPoints);
  void polyLine(const POINT *lppt, int cPoints);
  void chrod(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2);
  void ellipse(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);
  void pie(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2);
  void polygon(const POINT *lpPoints, int nCount);
  void rectangle(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect);
  void roundrect(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nWidth, int nHeight);
  ///
  void beginPaint();
  void endPaint();
  void clearDevice(void);
  int getWidth();
  int getHeight();
  void registerTimerEvent(TimerEventCallback callback);
  void startTimer(int timerID, int timeinterval);
  void cancelTimer(int timerID);
 public:
  QPen &getQPen();
  QBrush &getQBrush();
};


#endif //PROJECT_PAINTAREA_H
