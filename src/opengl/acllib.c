//
// Created by Colliot on 2016/8/7.
//

// Include standard headers
#include <stdio.h>
#include <stdlib.h>


#include <GL/glut.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "../common/acllib.h"

int test () {
  FT_Library ft;

  if(FT_Init_FreeType(&ft)) {
    fprintf(stderr, "Could not init freetype library\n");
    return 1;
  }

  FT_Face face;

  if(FT_New_Face(ft, "DejuVuSans.ttf", 0, &face)) {
    fprintf(stderr, "Could not open font\n");
    return 1;
  }

  return 0;
}

#include <math.h>

GLfloat light0_ambient[] =
    {0.2, 0.2, 0.2, 1.0};
GLfloat light0_diffuse[] =
    {0.0, 0.0, 0.0, 1.0};
GLfloat light1_diffuse[] =
    {1.0, 0.0, 0.0, 1.0};
GLfloat light1_position[] =
    {1.0, 1.0, 1.0, 0.0};
GLfloat light2_diffuse[] =
    {0.0, 1.0, 0.0, 1.0};
GLfloat light2_position[] =
    {-1.0, -1.0, 1.0, 0.0};
float s = 0.0;
GLfloat angle1 = 0.0, angle2 = 0.0;

void
output(GLfloat x, GLfloat y, char *text)
{
  char *p;

  glPushMatrix();
  glTranslatef(x, y, 0);
  for (p = text; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}

void
display(void)
{
  static GLfloat amb[] =
      {0.4, 0.4, 0.4, 0.0};
  static GLfloat dif[] =
      {1.0, 1.0, 1.0, 0.0};

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_LIGHT1);
  glDisable(GL_LIGHT2);
  amb[3] = dif[3] = cos(s) / 2.0 + 0.5;
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);

  glPushMatrix();
  glTranslatef(-0.3, -0.3, 0.0);
  glRotatef(angle1, 1.0, 5.0, 0.0);
  glCallList(1);        /* render ico display list */
  glPopMatrix();

  glClear(GL_DEPTH_BUFFER_BIT);
  glEnable(GL_LIGHT2);
  glDisable(GL_LIGHT1);
  amb[3] = dif[3] = 0.5 - cos(s * .95) / 2.0;
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);

  glPushMatrix();
  glTranslatef(0.3, 0.3, 0.0);
  glRotatef(angle2, 1.0, 0.0, 5.0);
  glCallList(1);        /* render ico display list */
  glPopMatrix();

  glPushAttrib(GL_ENABLE_BIT);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, 1500, 0, 1500);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  /* Rotate text slightly to help show jaggies. */
  glRotatef(4, 0.0, 0.0, 1.0);
  output(200, 225, "This is antialiased.");
  glDisable(GL_LINE_SMOOTH);
  glDisable(GL_BLEND);
  output(160, 100, "This text is not.");
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glPopAttrib();
  glMatrixMode(GL_MODELVIEW);

  glutSwapBuffers();
}


int main(int argc,
         char **argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

//  test();
//  Setup();
  initWindow("", 1, 1, 1, 1);
  return 0;
}

void initWindow(const char title[], int left, int top, int width, int height) {
  glutCreateWindow("blender");
  glutDisplayFunc(display);
//  glutVisibilityFunc(visible);

  glNewList(1, GL_COMPILE);  /* create ico display list */
  glutSolidIcosahedron();
  glEndList();

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
//  glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
//  glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
//  glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
//  glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
//  glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
//  glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  glLineWidth(2.0);

  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
      /* aspect ratio */ 1.0,
      /* Z near */ 1.0, /* Z far */ 10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
            0.0, 0.0, 0.0,      /* center is at (0,0,0) */
            0.0, 1.0, 0.);      /* up is in positive Y direction */
  glTranslatef(0.0, 0.6, -1.0);

  glutMainLoop();

  glBegin(GL_TRIANGLES);
  glColor3f(0.1, 0.2, 0.3);
  glVertex3f(0, 0, 0);
  glVertex3f(1, 0, 0);
  glVertex3f(0, 1, 0);
  glEnd();


//  GtkApplication *app;
//  app = gtk_application_window_new(app);

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
