#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    label = new QLabel("0", this);
    setCentralWidget(label);

    timer = new QTimer(this);
    count = 0;

    connect(timer, &QTimer::timeout, [this]() {
        label->setText(QString::number(count));
        count++;
    });

    timer->start(1000);
}

MainWindow::~MainWindow()
{
}
