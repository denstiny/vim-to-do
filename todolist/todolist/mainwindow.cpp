#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->textBrowser->setPalette(QPalette(QColor(0, 44, 52)));
  int width = this->geometry().width();
  int height = this->geometry().height();
  this->setFixedSize(width, height);
  setPalette(QPalette(QColor(40, 44, 52)));
  setAutoFillBackground(true);
  closeTimer = new QTimer(this);
  closeTimer->setSingleShot(true);
  connect(closeTimer, &QTimer::timeout, this, [=]() { this->close(); });
}

MainWindow::~MainWindow() {
  if (closeTimer != Q_NULLPTR) closeTimer->deleteLater();
  delete ui;
}

void MainWindow::startTimer() { closeTimer->start(3000); }

void MainWindow::DisPlayString(QString topic, QString date, QString due,
                               QString detail) {
  ui->textBrowser->setText(topic + '\n' + date + '\n' + due + '\n' + detail);
}
