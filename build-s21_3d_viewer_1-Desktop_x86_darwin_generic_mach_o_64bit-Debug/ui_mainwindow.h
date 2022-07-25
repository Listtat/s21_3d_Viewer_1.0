/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "widget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Widget *widget;
    QLineEdit *lineEdit_shiftX;
    QPushButton *pushButton_shifts;
    QLineEdit *lineEdit_shiftY;
    QLineEdit *lineEdit_shiftZ;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_rotate;
    QLineEdit *lineEdit_rotateY;
    QLineEdit *lineEdit_rotateZ;
    QLabel *label_5;
    QLineEdit *lineEdit_rotateX;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_scale;
    QLineEdit *lineEdit_scale;
    QPushButton *pushButton_open;
    QTextEdit *textEdit_info;
    QPushButton *pushButton_perspective;
    QPushButton *pushButton_ortho;
    QDoubleSpinBox *doubleSpinBox_red;
    QPushButton *pushButton_background_color;
    QDoubleSpinBox *doubleSpinBox_green;
    QDoubleSpinBox *doubleSpinBox_blue;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_red_edge;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_green_edge;
    QDoubleSpinBox *doubleSpinBox_blue_edge;
    QLabel *label_12;
    QPushButton *pushButton_edge;
    QLabel *label_13;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_width_edge;
    QLabel *label_15;
    QCheckBox *checkBox_dotted_line;
    QLabel *label_16;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_blue_point;
    QDoubleSpinBox *doubleSpinBox_red_point;
    QDoubleSpinBox *doubleSpinBox_green_point;
    QLabel *label_18;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_point_size;
    QLabel *label_20;
    QPushButton *pushButton_point;
    QRadioButton *radioButton_missing;
    QRadioButton *radioButton_circle;
    QRadioButton *radioButton_square;
    QPushButton *pushButton_save;
    QPushButton *pushButton_start_screencast;
    QPushButton *pushButton_stop_screencast;
    QCheckBox *checkBox_main_settings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 1084);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new Widget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 1000, 1000));
        lineEdit_shiftX = new QLineEdit(centralwidget);
        lineEdit_shiftX->setObjectName(QString::fromUtf8("lineEdit_shiftX"));
        lineEdit_shiftX->setGeometry(QRect(1100, 140, 113, 41));
        QFont font;
        font.setPointSize(20);
        lineEdit_shiftX->setFont(font);
        pushButton_shifts = new QPushButton(centralwidget);
        pushButton_shifts->setObjectName(QString::fromUtf8("pushButton_shifts"));
        pushButton_shifts->setGeometry(QRect(1260, 190, 131, 51));
        pushButton_shifts->setFont(font);
        lineEdit_shiftY = new QLineEdit(centralwidget);
        lineEdit_shiftY->setObjectName(QString::fromUtf8("lineEdit_shiftY"));
        lineEdit_shiftY->setGeometry(QRect(1270, 140, 113, 41));
        lineEdit_shiftY->setFont(font);
        lineEdit_shiftZ = new QLineEdit(centralwidget);
        lineEdit_shiftZ->setObjectName(QString::fromUtf8("lineEdit_shiftZ"));
        lineEdit_shiftZ->setGeometry(QRect(1440, 140, 113, 41));
        lineEdit_shiftZ->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1070, 140, 31, 41));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1240, 140, 31, 41));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1410, 140, 31, 41));
        label_4->setFont(font);
        pushButton_rotate = new QPushButton(centralwidget);
        pushButton_rotate->setObjectName(QString::fromUtf8("pushButton_rotate"));
        pushButton_rotate->setGeometry(QRect(1260, 310, 131, 51));
        pushButton_rotate->setFont(font);
        lineEdit_rotateY = new QLineEdit(centralwidget);
        lineEdit_rotateY->setObjectName(QString::fromUtf8("lineEdit_rotateY"));
        lineEdit_rotateY->setGeometry(QRect(1270, 260, 113, 41));
        lineEdit_rotateY->setFont(font);
        lineEdit_rotateZ = new QLineEdit(centralwidget);
        lineEdit_rotateZ->setObjectName(QString::fromUtf8("lineEdit_rotateZ"));
        lineEdit_rotateZ->setGeometry(QRect(1440, 260, 113, 41));
        lineEdit_rotateZ->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1070, 260, 31, 41));
        label_5->setFont(font);
        lineEdit_rotateX = new QLineEdit(centralwidget);
        lineEdit_rotateX->setObjectName(QString::fromUtf8("lineEdit_rotateX"));
        lineEdit_rotateX->setGeometry(QRect(1100, 260, 113, 41));
        lineEdit_rotateX->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1240, 260, 31, 41));
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1410, 260, 31, 41));
        label_7->setFont(font);
        pushButton_scale = new QPushButton(centralwidget);
        pushButton_scale->setObjectName(QString::fromUtf8("pushButton_scale"));
        pushButton_scale->setGeometry(QRect(1260, 370, 131, 51));
        pushButton_scale->setFont(font);
        lineEdit_scale = new QLineEdit(centralwidget);
        lineEdit_scale->setObjectName(QString::fromUtf8("lineEdit_scale"));
        lineEdit_scale->setGeometry(QRect(1100, 380, 113, 41));
        lineEdit_scale->setFont(font);
        pushButton_open = new QPushButton(centralwidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(1080, 10, 131, 101));
        pushButton_open->setFont(font);
        textEdit_info = new QTextEdit(centralwidget);
        textEdit_info->setObjectName(QString::fromUtf8("textEdit_info"));
        textEdit_info->setGeometry(QRect(1230, 10, 351, 101));
        textEdit_info->setFont(font);
        pushButton_perspective = new QPushButton(centralwidget);
        pushButton_perspective->setObjectName(QString::fromUtf8("pushButton_perspective"));
        pushButton_perspective->setGeometry(QRect(1120, 450, 171, 51));
        pushButton_perspective->setFont(font);
        pushButton_ortho = new QPushButton(centralwidget);
        pushButton_ortho->setObjectName(QString::fromUtf8("pushButton_ortho"));
        pushButton_ortho->setGeometry(QRect(1340, 450, 171, 51));
        pushButton_ortho->setFont(font);
        doubleSpinBox_red = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_red->setObjectName(QString::fromUtf8("doubleSpinBox_red"));
        doubleSpinBox_red->setGeometry(QRect(1130, 510, 81, 41));
        QFont font1;
        font1.setPointSize(30);
        doubleSpinBox_red->setFont(font1);
        doubleSpinBox_red->setMaximum(1.000000000000000);
        doubleSpinBox_red->setSingleStep(0.010000000000000);
        pushButton_background_color = new QPushButton(centralwidget);
        pushButton_background_color->setObjectName(QString::fromUtf8("pushButton_background_color"));
        pushButton_background_color->setGeometry(QRect(1230, 560, 191, 51));
        pushButton_background_color->setFont(font);
        doubleSpinBox_green = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_green->setObjectName(QString::fromUtf8("doubleSpinBox_green"));
        doubleSpinBox_green->setGeometry(QRect(1300, 510, 81, 41));
        doubleSpinBox_green->setFont(font1);
        doubleSpinBox_green->setMaximum(1.000000000000000);
        doubleSpinBox_green->setSingleStep(0.010000000000000);
        doubleSpinBox_blue = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_blue->setObjectName(QString::fromUtf8("doubleSpinBox_blue"));
        doubleSpinBox_blue->setGeometry(QRect(1470, 510, 81, 41));
        doubleSpinBox_blue->setFont(font1);
        doubleSpinBox_blue->setMaximum(1.000000000000000);
        doubleSpinBox_blue->setSingleStep(0.010000000000000);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1070, 510, 51, 41));
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(1230, 510, 71, 41));
        label_9->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(1410, 510, 71, 41));
        label_10->setFont(font);
        doubleSpinBox_red_edge = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_red_edge->setObjectName(QString::fromUtf8("doubleSpinBox_red_edge"));
        doubleSpinBox_red_edge->setGeometry(QRect(1130, 660, 81, 41));
        doubleSpinBox_red_edge->setFont(font1);
        doubleSpinBox_red_edge->setMaximum(1.000000000000000);
        doubleSpinBox_red_edge->setSingleStep(0.010000000000000);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(1410, 660, 71, 41));
        label_11->setFont(font);
        doubleSpinBox_green_edge = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_green_edge->setObjectName(QString::fromUtf8("doubleSpinBox_green_edge"));
        doubleSpinBox_green_edge->setGeometry(QRect(1300, 660, 81, 41));
        doubleSpinBox_green_edge->setFont(font1);
        doubleSpinBox_green_edge->setMaximum(1.000000000000000);
        doubleSpinBox_green_edge->setSingleStep(0.010000000000000);
        doubleSpinBox_blue_edge = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_blue_edge->setObjectName(QString::fromUtf8("doubleSpinBox_blue_edge"));
        doubleSpinBox_blue_edge->setGeometry(QRect(1470, 660, 81, 41));
        doubleSpinBox_blue_edge->setFont(font1);
        doubleSpinBox_blue_edge->setMaximum(1.000000000000000);
        doubleSpinBox_blue_edge->setSingleStep(0.010000000000000);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(1070, 660, 51, 41));
        label_12->setFont(font);
        pushButton_edge = new QPushButton(centralwidget);
        pushButton_edge->setObjectName(QString::fromUtf8("pushButton_edge"));
        pushButton_edge->setGeometry(QRect(1220, 750, 191, 51));
        pushButton_edge->setFont(font);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(1230, 660, 71, 41));
        label_13->setFont(font);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(1250, 620, 161, 41));
        label_14->setFont(font);
        doubleSpinBox_width_edge = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_width_edge->setObjectName(QString::fromUtf8("doubleSpinBox_width_edge"));
        doubleSpinBox_width_edge->setGeometry(QRect(1190, 710, 81, 41));
        doubleSpinBox_width_edge->setFont(font1);
        doubleSpinBox_width_edge->setMaximum(999.000000000000000);
        doubleSpinBox_width_edge->setSingleStep(1.000000000000000);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(1070, 710, 121, 41));
        label_15->setFont(font);
        checkBox_dotted_line = new QCheckBox(centralwidget);
        checkBox_dotted_line->setObjectName(QString::fromUtf8("checkBox_dotted_line"));
        checkBox_dotted_line->setGeometry(QRect(1300, 720, 121, 20));
        checkBox_dotted_line->setFont(font);
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(1410, 840, 71, 41));
        label_16->setFont(font);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(1230, 840, 71, 41));
        label_17->setFont(font);
        doubleSpinBox_blue_point = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_blue_point->setObjectName(QString::fromUtf8("doubleSpinBox_blue_point"));
        doubleSpinBox_blue_point->setGeometry(QRect(1470, 840, 81, 41));
        doubleSpinBox_blue_point->setFont(font1);
        doubleSpinBox_blue_point->setMaximum(1.000000000000000);
        doubleSpinBox_blue_point->setSingleStep(0.010000000000000);
        doubleSpinBox_red_point = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_red_point->setObjectName(QString::fromUtf8("doubleSpinBox_red_point"));
        doubleSpinBox_red_point->setGeometry(QRect(1130, 840, 81, 41));
        doubleSpinBox_red_point->setFont(font1);
        doubleSpinBox_red_point->setMaximum(1.000000000000000);
        doubleSpinBox_red_point->setSingleStep(0.010000000000000);
        doubleSpinBox_green_point = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_green_point->setObjectName(QString::fromUtf8("doubleSpinBox_green_point"));
        doubleSpinBox_green_point->setGeometry(QRect(1300, 840, 81, 41));
        doubleSpinBox_green_point->setFont(font1);
        doubleSpinBox_green_point->setMaximum(1.000000000000000);
        doubleSpinBox_green_point->setSingleStep(0.010000000000000);
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(1070, 840, 51, 41));
        label_18->setFont(font);
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(1250, 800, 161, 41));
        label_19->setFont(font);
        doubleSpinBox_point_size = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_point_size->setObjectName(QString::fromUtf8("doubleSpinBox_point_size"));
        doubleSpinBox_point_size->setGeometry(QRect(1190, 890, 81, 41));
        doubleSpinBox_point_size->setFont(font1);
        doubleSpinBox_point_size->setMaximum(999.000000000000000);
        doubleSpinBox_point_size->setSingleStep(1.000000000000000);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(1070, 890, 121, 41));
        label_20->setFont(font);
        pushButton_point = new QPushButton(centralwidget);
        pushButton_point->setObjectName(QString::fromUtf8("pushButton_point"));
        pushButton_point->setGeometry(QRect(1220, 930, 191, 51));
        pushButton_point->setFont(font);
        radioButton_missing = new QRadioButton(centralwidget);
        radioButton_missing->setObjectName(QString::fromUtf8("radioButton_missing"));
        radioButton_missing->setGeometry(QRect(1290, 900, 99, 21));
        radioButton_missing->setFont(font);
        radioButton_circle = new QRadioButton(centralwidget);
        radioButton_circle->setObjectName(QString::fromUtf8("radioButton_circle"));
        radioButton_circle->setGeometry(QRect(1390, 900, 99, 21));
        radioButton_circle->setFont(font);
        radioButton_square = new QRadioButton(centralwidget);
        radioButton_square->setObjectName(QString::fromUtf8("radioButton_square"));
        radioButton_square->setGeometry(QRect(1480, 900, 99, 21));
        radioButton_square->setFont(font);
        pushButton_save = new QPushButton(centralwidget);
        pushButton_save->setObjectName(QString::fromUtf8("pushButton_save"));
        pushButton_save->setGeometry(QRect(20, 1010, 191, 51));
        pushButton_save->setFont(font);
        pushButton_start_screencast = new QPushButton(centralwidget);
        pushButton_start_screencast->setObjectName(QString::fromUtf8("pushButton_start_screencast"));
        pushButton_start_screencast->setGeometry(QRect(240, 1010, 191, 51));
        pushButton_start_screencast->setFont(font);
        pushButton_stop_screencast = new QPushButton(centralwidget);
        pushButton_stop_screencast->setObjectName(QString::fromUtf8("pushButton_stop_screencast"));
        pushButton_stop_screencast->setGeometry(QRect(460, 1010, 191, 51));
        pushButton_stop_screencast->setFont(font);
        checkBox_main_settings = new QCheckBox(centralwidget);
        checkBox_main_settings->setObjectName(QString::fromUtf8("checkBox_main_settings"));
        checkBox_main_settings->setGeometry(QRect(1070, 110, 141, 20));
        checkBox_main_settings->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_shiftX->setText(QString());
        pushButton_shifts->setText(QCoreApplication::translate("MainWindow", "--Shifts--", nullptr));
        lineEdit_shiftY->setText(QString());
        lineEdit_shiftZ->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "X=", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Y=", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Z=", nullptr));
        pushButton_rotate->setText(QCoreApplication::translate("MainWindow", "--Rotate--", nullptr));
        lineEdit_rotateY->setText(QString());
        lineEdit_rotateZ->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "X=", nullptr));
        lineEdit_rotateX->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Y=", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Z=", nullptr));
        pushButton_scale->setText(QCoreApplication::translate("MainWindow", "--Scale--", nullptr));
        lineEdit_scale->setText(QString());
        pushButton_open->setText(QCoreApplication::translate("MainWindow", "OPEN .obj", nullptr));
        textEdit_info->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_perspective->setText(QCoreApplication::translate("MainWindow", "PERSPECTIVE", nullptr));
        pushButton_ortho->setText(QCoreApplication::translate("MainWindow", "ORTHOGRAPHIC", nullptr));
        pushButton_background_color->setText(QCoreApplication::translate("MainWindow", "--Background Color--", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "RED:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "GREEN:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "BLUE:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "BLUE:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "RED:", nullptr));
        pushButton_edge->setText(QCoreApplication::translate("MainWindow", "--Edge--", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "GREEN:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "--Settings Edge--", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Width edges:", nullptr));
        checkBox_dotted_line->setText(QCoreApplication::translate("MainWindow", "Dotted line", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "BLUE:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "GREEN:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "RED:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "--Settings Point--", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Point size:", nullptr));
        pushButton_point->setText(QCoreApplication::translate("MainWindow", "--Point--", nullptr));
        radioButton_missing->setText(QCoreApplication::translate("MainWindow", "Missing", nullptr));
        radioButton_circle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        radioButton_square->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        pushButton_save->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        pushButton_start_screencast->setText(QCoreApplication::translate("MainWindow", "Start Screencast", nullptr));
        pushButton_stop_screencast->setText(QCoreApplication::translate("MainWindow", "Stop Screencast", nullptr));
        checkBox_main_settings->setText(QCoreApplication::translate("MainWindow", "main_settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
