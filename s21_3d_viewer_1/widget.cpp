#include "widget.h"
#include "ui_widget.h"

void Widget::initializeGL()
{
    setGeometry(0, 0, 1000, 1000);
    glEnable(GL_DEPTH_TEST);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2, 6);
}

void Widget::paintGL()
{
    glClearColor(mas_color[0], mas_color[1], mas_color[2], 0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -4);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    if (flag == 0) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-3, 3, -3, 3, 2, 6);
    } else {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-3, 3, -3, 3, 2, 6);
    }
    draw();
}

void Widget::draw()
{
    for (unsigned int i = 1; i < main_struct.count_of_vertexes + 1; i++) {
        if (flag_draw_point == 0) {}
        else if (flag_draw_point == 1) {
            glPointSize(size_point);
            glEnable(GL_POINT_SMOOTH);
            glBegin(GL_POINTS);
            glColor3d(mas_color_points[0], mas_color_points[1], mas_color_points[2]);
            glVertex3d(main_struct.matrix_3d.matrix[i][0], main_struct.matrix_3d.matrix[i][1], main_struct.matrix_3d.matrix[i][2]);
            glEnd();
            glDisable(GL_POINT_SMOOTH);
        } else if (flag_draw_point == 2) {
            glBegin(GL_POINTS);
            glColor3d(mas_color_points[0], mas_color_points[1], mas_color_points[2]);
            glVertex3d(main_struct.matrix_3d.matrix[i][0], main_struct.matrix_3d.matrix[i][1], main_struct.matrix_3d.matrix[i][2]);
            glEnd();
        }
    }

    for (unsigned int i = 1; i < main_struct.count_of_facets; i++) {
        for (unsigned int j = 0; j < main_struct.polygons[i].numbers_of_vertexes_in_facets; j++) {
            if (j == (main_struct.polygons[i].numbers_of_vertexes_in_facets - 1)) {
                if (flag_dotted_line == 1) {
                    glLineWidth(width_edges);
                    glBegin(GL_LINE_STRIP);
                    glColor3d(mas_color_edges[0], mas_color_edges[1], mas_color_edges[2]);
                    glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][2]);
                    glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][2]);
                    glEnd();
                    glEnable(GL_LINE_SMOOTH);
                    glEnable(GL_LINE_STIPPLE);
                    glLineStipple(20, 0x3333);
                    break;
                } else if (flag_dotted_line == 0) {
                    glLineWidth(width_edges);
                    glBegin(GL_LINES);
                    glColor3d(mas_color_edges[0], mas_color_edges[1], mas_color_edges[2]);
                    glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][2]);
                    glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][2]);
                    glEnd();
                    glDisable(GL_LINE_SMOOTH);
                    glDisable(GL_LINE_STIPPLE);
                    break;
                }
            }
            if (flag_dotted_line == 1) {
                glLineWidth(width_edges);
                glBegin(GL_LINE_STRIP);
                glColor3d(mas_color_edges[0], mas_color_edges[1], mas_color_edges[2]);
                glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][2]);
                glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j + 1]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j + 1]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j + 1]][2]);
                glEnd();
                glEnable(GL_LINE_SMOOTH);
                glEnable(GL_LINE_STIPPLE);
                glLineStipple(20, 0x3333);
            } else if (flag_dotted_line == 0) {
                glLineWidth(width_edges);
                glBegin(GL_LINES);
                glColor3d(mas_color_edges[0], mas_color_edges[1], mas_color_edges[2]);
                glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[j]][2]);
                glVertex3d(main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][0], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][1], main_struct.matrix_3d.matrix[main_struct.polygons[i].vertexes[0]][2]);
                glEnd();
                glDisable(GL_LINE_SMOOTH);
                glDisable(GL_LINE_STIPPLE);
            }
        }
    }
}

void Widget::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

void Widget::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1/M_PI*(mo->pos().y() - mPos.y());
    yRot = 1/M_PI*(mo->pos().x() - mPos.x());
    update();
}

void Widget::shift(double* coord)
{
    s21_shift(&main_struct, coord);
    update();
}

void Widget::rotate(double* rotation)
{
    s21_rotate_x(&main_struct, rotation[0]);
    s21_rotate_y(&main_struct, rotation[1]);
    s21_rotate_z(&main_struct, rotation[2]);
    update();
}

void Widget::scaling(double scale)
{
    s21_scaling(&main_struct, scale);
    update();
}

void Widget::open(int flag_settings)
{
    QString path_to_file = QFileDialog::getOpenFileName(NULL, "Open", "", "*.obj");
    char* path_to_file_str = new char[path_to_file.length()];
    QByteArray barr = path_to_file.toLatin1();
    strlcpy(path_to_file_str, barr, path_to_file.length() + 1);
    s21_3d(&main_struct, path_to_file_str);
    char* file_name_str = strrchr(path_to_file_str, '/');
    if (file_name_str != NULL) {
        file_name_str += 1;
        file_name = QString::fromUtf8(file_name_str);
        open_config_file(path_to_file_str, file_name_str, flag_settings);
    }
    delete[] path_to_file_str;
    path_to_file_str = NULL;
    update();
}

void Widget::change_projection(int input_flag)
{
    flag = input_flag;
    update();
}

void Widget::open_config_file(char* path_to_file_str, char* file_name_str, int flag_settings)
{
    char main_config[256];
    char file_name_main_config[16] = "main_CONFIG.txt";
    memset(main_config, '\0', 256);
    char name[256];
    memset(name, '\0', 256);
    char config[12] = "_CONFIG.txt";
    char path[256] = "Configs/";
    strncpy(name, file_name_str, strlen(file_name_str) - 4);
    char new_path[256];
    memset(new_path, '\0', 256);
    strncpy(new_path, path_to_file_str, strlen(path_to_file_str) - strlen(file_name_str));
    strcat(new_path, path);
    strcat(main_config, new_path);
    strcat(main_config, file_name_main_config);
    strcat(new_path, name);
    strcat(new_path, config);


    file_for_write = fopen(new_path, "r");
    if (file_for_write == NULL || flag_settings == 1) {
        file_for_write = fopen(new_path, "w");
    } else {
        char s[256];
        memset(s, '\0', 256);

        fgets(s, 5, file_for_write);
        flag = atoi(s);

        fgets(s, 5, file_for_write);
        mas_color[0] = atof(s);

        fgets(s, 5, file_for_write);
        mas_color[1] = atof(s);

        fgets(s, 5, file_for_write);
        mas_color[2] = atof(s);

        fgets(s, 5, file_for_write);
        mas_color_edges[0] = atof(s);

        fgets(s, 5, file_for_write);
        mas_color_edges[1] = atof(s);

        fgets(s, 5, file_for_write);
        mas_color_edges[2] = atof(s);

        fgets(s, 5, file_for_write);
        width_edges = atof(s);

        fgets(s, 5, file_for_write);
        flag_dotted_line = atoi(s);

        fgets(s, 5, file_for_write);
        mas_color_points[0] = atof(s);

        fgets(s, 5, file_for_write);
        mas_color_points[1] = atof(s);

        fgets(s, 5, file_for_write);
        mas_color_points[2] = atof(s);

        fgets(s, 5, file_for_write);
        size_point = atof(s);

        fgets(s, 5, file_for_write);
        flag_draw_point = atoi(s);

        fclose(file_for_write);
        file_for_write = fopen(new_path, "w");
    }
}
