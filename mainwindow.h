#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QAction>
#include <QMenu>
#include <QFileDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeFont();
    void changeFontColor();
    void changeBackgroundColor();
    void setBackgroundImage();

private:
    QLabel *label;
    QTimer *timer;
    int count;

    QAction *fontAction;
    QAction *fontColorAction;
    QAction *backgroundColorAction;
    QAction *backgroundImageAction;
};

#endif // MAINWINDOW_H
