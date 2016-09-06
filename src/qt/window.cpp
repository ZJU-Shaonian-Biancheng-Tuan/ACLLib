//
// Created by Colliot on 2016/9/6.
//

#include "window.h"


void initWindow(const char title[], int left, int top, int width, int height) {

  pMainWindow = new QMainWindow();
  pGlobalWidget = new AclGlobalWidget();
  pMainWindow->setCentralWidget(pGlobalWidget);
  pMainWindow->setWindowTitle(title);
  pMainWindow->resize(width, height);
  pMainWindow->move(left, top);
  pMainWindow->show();
//  GtkApplication *app;
//  app = gtk_application_window_new(app);

}

///
/// \param title
/// \param text
/// \param flag
void msgBox(const char title[], const char text[], int flag) {
  QMessageBox messageBox; // TODO: The behavior is different from Windows API.
  messageBox.setWindowTitle(title);
  messageBox.setText(text);
  messageBox.exec();
}