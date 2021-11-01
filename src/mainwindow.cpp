#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>
#include <iostream>
using std::string;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string str = "Hello";
    QString qs = QString::fromStdString(str);
    ui->textEdit->append(qs);
#if QT_VERSION_MAJOR < 6
    ui->textEdit->append(
        QString::fromStdString(
            std::string(
                QT_VERSION_STR)));
#else
    ui->textEdit->append(
        QString::fromStdString(
            std::string(
                QT_VERSION_STR)));
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}
