#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void startTimer();
  void DisPlayString(QString topic, QString date, QString due, QString detail);

 private:
  Ui::MainWindow *ui;
  QTimer *closeTimer;
};
#endif  // MAINWINDOW_H
