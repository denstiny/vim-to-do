#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QString topic, date, due, detail;
  topic = "topic";
  date = "date";
  due = "due";
  detail = "detail";
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  w.DisPlayString(topic, date, due, detail);
  w.startTimer();
  return a.exec();
}
