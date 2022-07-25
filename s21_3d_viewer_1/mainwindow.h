#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include <QMessageBox>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include "widget.h"
#include "../QtGifImage-master/src/gifimage/qgifimage.h"
#include <QVector>
#include <QImage>
#include <QPainter>
#include <QPixmap>
#include <QSize>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector<QImage> mas_image;

private slots:
    void press_shift();
    void press_rotate();
    void press_scale();
    void press_open();
    void press_persp();
    void press_ortho();
    void press_background_color();
    void press_edge();
    void press_point();
    void press_save();
    void press_start_screencast();
    void press_stop_screencast();

    void create_screen();

private:
    Ui::MainWindow *ui;
    QDoubleValidator validator;
    void write();
    int flag_record = 0;
};

#endif // MAINWINDOW_H
