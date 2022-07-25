#ifndef WIDGET_H
#define WIDGET_H
#define GL_SILENCE_DEPRECATION

#include <QWidget>
#include <QtOpenGLWidgets/qopenglwidget.h>
#include <QOpenGLFunctions>
#include <QGuiApplication>
#include <QMouseEvent>
#include <QGridLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QByteArray>
#include <stdlib.h>
#include <QDir>

#ifdef __cplusplus
extern "C" {
#include "../s21_3D_Viewer_1.0.h"
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QOpenGLWidget
{
    Q_OBJECT
private:
    float xRot, yRot, zRot;
    QPoint mPos;
    void draw();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;

public:
    int flag = 0;
    my_data main_struct;
    QString file_name;
    GLfloat mas_color[3] = {0, 0, 0};
    GLdouble mas_color_edges[3] = {1, 1, 1};
    GLfloat width_edges = 1;
    int flag_dotted_line = 0;

    GLdouble mas_color_points[3] = {1, 1, 1};
    GLfloat size_point = 1;
    int flag_draw_point = 2;

    FILE *file_for_write = NULL;


    Widget(QWidget *parent = nullptr) : QOpenGLWidget(parent) {
        main_struct.count_of_facets = 0;
        main_struct.count_of_vertexes = 0;
        main_struct.polygons = NULL;
        main_struct.matrix_3d.matrix = NULL;
        main_struct.matrix_3d.columns = 0;
        main_struct.matrix_3d.rows = 0;

    }

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void shift(double* coord);
    void rotate(double* rotation);
    void scaling(double scale);
    void open(int flag_settings);
    void change_projection(int input_flag);
    void open_config_file(char* path_to_file_str, char* file_name_str, int flag_settings);


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
