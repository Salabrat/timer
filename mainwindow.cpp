#include "mainwindow.h"
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QFont>
#include <QColor>
#include <QAction>
#include <QMenu>
#include <QFileDialog>
#include <QFontDialog>
#include <QMenuBar>



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

    // Создание меню
    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *formatMenu = menuBar->addMenu("Формат");

    QAction *fontAction = new QAction("Изменить шрифт", this);
    connect(fontAction, &QAction::triggered, this, &MainWindow::changeFont);
    formatMenu->addAction(fontAction);

    QAction *fontColorAction = new QAction("Изменить цвет шрифта", this);
    connect(fontColorAction, &QAction::triggered, this, &MainWindow::changeFontColor);
    formatMenu->addAction(fontColorAction);

    QAction *bgColorAction = new QAction("Изменить цвет заднего фона", this);
    connect(bgColorAction, &QAction::triggered, this, &MainWindow::changeBackgroundColor);
    formatMenu->addAction(bgColorAction);

    QAction *bgImageAction = new QAction("Установить фоновое изображение", this);
    connect(bgImageAction, &QAction::triggered, this, &MainWindow::setBackgroundImage);
    formatMenu->addAction(bgImageAction);
}

MainWindow::~MainWindow()
{
}

void MainWindow::changeFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, label->font(), this);
    if (ok)
        label->setFont(font);
}

void MainWindow::changeFontColor()
{
    QColor color = QColorDialog::getColor(label->palette().color(QPalette::WindowText), this);
    if (color.isValid())
        label->setStyleSheet(QString("color: %1;").arg(color.name()));
}

void MainWindow::changeBackgroundColor()
{
    QColor color = QColorDialog::getColor(label->palette().color(QPalette::Window), this);
    if (color.isValid())
        setStyleSheet(QString("background-color: %1;").arg(color.name()));
}

void MainWindow::setBackgroundImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Выберите фоновое изображение", "", "Изображения (*.png *.jpg)");
    if (!fileName.isEmpty())
        setStyleSheet(QString("background-image: url(%1); background-repeat: no-repeat; background-position: center;").arg(fileName));
}
