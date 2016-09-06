//
// Created by Colliot on 2016/9/6.
//

#include "PaintArea.h"

W_OBJECT_IMPL(AclGlobalWidget)
/// Handle mouse press events.
/// \param event
void AclGlobalWidget::mousePressEvent(QMouseEvent *event) {
  qDebug() << event->x();
  if (event->button() == Qt::LeftButton) {
    // handle left mouse button here
  } else {
    // pass on other buttons to base class
  }
}
AclGlobalWidget::AclGlobalWidget()
    : currentPoint(new Point(0, 0)),
      qPen(QColor(0, 0, 0), Qt::SolidPattern),
      qBrush(QColor(0, 0, 0), Qt::SolidPattern) {
  qPen.setWidth(1);
}
AclGlobalWidget::~AclGlobalWidget() {
  delete timer;
  delete currentPoint;
}

// the Point
int AclGlobalWidget::getX(void) {
  return currentPoint->x;
}
int AclGlobalWidget::getY(void) {
  return currentPoint->y;
}
void AclGlobalWidget::moveTo(int x, int y) {
  currentPoint->x = x;
  currentPoint->y = y;
}
void AclGlobalWidget::moveRel(int dx, int dy) {
  currentPoint->x += dx;
  currentPoint->y += dy;
}

void AclGlobalWidget::addLine(int startX, int startY, int endX, int endY) {
  QPainter painter(&image);
  painter.drawLine(startX, startY, endX, endY);
}

void AclGlobalWidget::addLineTo(int endX, int endY) {
  QPainter painter(&image);
  painter.drawLine(currentPoint->x, currentPoint->y, endX, endY);
}

void AclGlobalWidget::lineRel(int dx, int dy) {

}
void AclGlobalWidget::polyBezier(const POINT *lppt, int cPoints) {

}
void AclGlobalWidget::polyLine(const POINT *lppt, int cPoints) {

}

// Filled Shapes
void AclGlobalWidget::chrod(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2) {

}
void AclGlobalWidget::ellipse(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) {
  QPainter painter(&image);
  painter.drawEllipse(nLeftRect, nTopRect, nRightRect, nBottomRect);
}
void AclGlobalWidget::pie(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nXRadial1, int nYRadial1, int nXRadial2, int nYRadial2) {

}
void AclGlobalWidget::polygon(const POINT *lpPoints, int nCount) {

}
void AclGlobalWidget::rectangle(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect) {

}
void AclGlobalWidget::roundrect(int nLeftRect, int nTopRect, int nRightRect, int nBottomRect, \
    int nWidth, int nHeight) {

}

void AclGlobalWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QRect dirtyRect = event->rect();
  painter.drawImage(dirtyRect, image, dirtyRect);
//  QPainter painter(this);
//  painter.setPen(qPen);
//  painter.setBrush(qBrush);
//  painter.setRenderHints(QPainter::HighQualityAntialiasing, true);
////  painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
//  for (auto &line: lines) {
    
//  }
//  for (auto &ellipse: ellipses) {
////    painter.drawEllipse(ellipse);
//  }
}

void AclGlobalWidget::resizeEvent(QResizeEvent *event)
{
  if (width() > image.width() || height() > image.height()) {
    int newWidth = qMax(width() + 128, image.width());
    int newHeight = qMax(height() + 128, image.height());
    resizeImage(&image, QSize(newWidth, newHeight));
    update();
  }
  QWidget::resizeEvent(event);
}

void AclGlobalWidget::resizeImage(QImage *image, const QSize &newSize)
//! [19] //! [20]
{
  if (image->size() == newSize)
    return;

  QImage newImage(newSize, QImage::Format_RGB32);
  newImage.fill(qRgb(255, 255, 255));
  QPainter painter(&newImage);
  painter.drawImage(QPoint(0, 0), *image);
  *image = newImage;
}

void AclGlobalWidget::timerListener(int timerId) {
  if (timerEventCallback != nullptr) {
    timerEventCallback(timerId);
  }
}

void AclGlobalWidget::beginPaint() {

}
void AclGlobalWidget::endPaint() {
  update();
}
void AclGlobalWidget::clearDevice(void) {
  image.fill(qRgb(255, 255, 255));
}
int AclGlobalWidget::getWidth() {

}
int AclGlobalWidget::getHeight() {

}

void AclGlobalWidget::registerTimerEvent(TimerEventCallback callback) {
  timerEventCallback = callback;
}


void AclGlobalWidget::startTimer(int timerID, int timeinterval) {
  auto newTimer = new IntTimer(this, timerID);
  connect(newTimer, SIGNAL(timeoutWithId(int)), this, SLOT(timerListener(int)));
  newTimer->start(timeinterval);
  timers[timerID] = newTimer;
}
void AclGlobalWidget::cancelTimer(int timerID) {
  auto timerToCancel = timers[timerID];
  timers.erase(timerID);
  delete timerToCancel;
}
QPen &AclGlobalWidget::getQPen() {
  return qPen;
}
QBrush &AclGlobalWidget::getQBrush() {
  return qBrush;
}