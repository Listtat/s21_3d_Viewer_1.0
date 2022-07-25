#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    QLocale locale(QLocale::English);
    validator.setLocale(locale);
    validator.setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_scale->setValidator(&validator);

    connect(ui->pushButton_shifts, SIGNAL(clicked()), this, SLOT(press_shift()));
    connect(ui->pushButton_rotate, SIGNAL(clicked()), this, SLOT(press_rotate()));
    connect(ui->pushButton_scale, SIGNAL(clicked()), this, SLOT(press_scale()));
    connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(press_open()));
    connect(ui->pushButton_perspective, SIGNAL(clicked()), this, SLOT(press_persp()));
    connect(ui->pushButton_ortho, SIGNAL(clicked()), this, SLOT(press_ortho()));
    connect(ui->pushButton_background_color, SIGNAL(clicked()), this, SLOT(press_background_color()));
    connect(ui->pushButton_edge, SIGNAL(clicked()), this, SLOT(press_edge()));
    connect(ui->pushButton_point, SIGNAL(clicked()), this, SLOT(press_point()));
    connect(ui->pushButton_save, SIGNAL(clicked()), this, SLOT(press_save()));
    connect(ui->pushButton_start_screencast, SIGNAL(clicked()), this, SLOT(press_start_screencast()));
    connect(ui->pushButton_stop_screencast, SIGNAL(clicked()), this, SLOT(press_stop_screencast()));
}

MainWindow::~MainWindow()
{
    if (ui->widget->file_for_write != NULL) {
        write();
        fclose(ui->widget->file_for_write);
    }
    delete ui;
}

void MainWindow::press_shift()
{
    double shiftX = ui->lineEdit_shiftX->text().toDouble();
    double shiftY = ui->lineEdit_shiftY->text().toDouble();
    double shiftZ = ui->lineEdit_shiftZ->text().toDouble();

    double coord[3];
    coord[0] = shiftX;
    coord[1] = shiftY;
    coord[2] = shiftZ;

    ui->widget->shift(coord);
    create_screen();
}

void MainWindow::press_rotate()
{
    double rotateX = ui->lineEdit_rotateX->text().toDouble();
    double rotateY = ui->lineEdit_rotateY->text().toDouble();
    double rotateZ = ui->lineEdit_rotateZ->text().toDouble();

    double rotation[3];
    rotation[0] = rotateX;
    rotation[1] = rotateY;
    rotation[2] = rotateZ;

    ui->widget->rotate(rotation);
    create_screen();
}

void MainWindow::press_scale()
{
    if (!ui->lineEdit_scale->text().contains(',')) {
        double scale = ui->lineEdit_scale->text().toDouble();
        if (scale != 0) {
            ui->widget->scaling(scale);
            create_screen();
        } else {
            QMessageBox::critical(this, "Масштабирование на 0", "Поле Scale не может быть равно 0");
        }
    } else {
        QMessageBox::information(this, "Наличие запятой", "Введите данные через точку");
    }
}

void MainWindow::press_open()
{
    int flag_settings = 0;
    if (ui->checkBox_main_settings->isChecked()) {
        flag_settings = 1;
    }
    ui->widget->open(flag_settings);

    ui->textEdit_info->setText("Название файла: " + ui->widget->file_name);
    ui->textEdit_info->append("Количество вершин: " + QString::number(ui->widget->main_struct.count_of_vertexes));
    ui->textEdit_info->append("Количество ребер: " + QString::number(ui->widget->main_struct.count_of_facets));
    ui->textEdit_info->setDisabled(true);

    ui->doubleSpinBox_red->setValue(ui->widget->mas_color[0]);
    ui->doubleSpinBox_green->setValue(ui->widget->mas_color[1]);
    ui->doubleSpinBox_blue->setValue(ui->widget->mas_color[2]);

    ui->doubleSpinBox_red_edge->setValue(ui->widget->mas_color_edges[0]);
    ui->doubleSpinBox_green_edge->setValue(ui->widget->mas_color_edges[1]);
    ui->doubleSpinBox_blue_edge->setValue(ui->widget->mas_color_edges[2]);
    ui->doubleSpinBox_width_edge->setValue(ui->widget->width_edges);
    if (ui->widget->flag_dotted_line) {
        ui->checkBox_dotted_line->setChecked(true);
    }

    ui->doubleSpinBox_red_point->setValue(ui->widget->mas_color_points[0]);
    ui->doubleSpinBox_green_point->setValue(ui->widget->mas_color_points[1]);
    ui->doubleSpinBox_blue_point->setValue(ui->widget->mas_color_points[2]);
    ui->doubleSpinBox_point_size->setValue(ui->widget->size_point);
    if (ui->widget->flag_draw_point == 0) {
        ui->radioButton_missing->setChecked(true);
    } else if (ui->widget->flag_draw_point == 1) {
        ui->radioButton_circle->setChecked(true);
    } else if (ui->widget->flag_draw_point == 2) {
        ui->radioButton_square->setChecked(true);
    }
}

void MainWindow::press_persp()
{
    ui->widget->change_projection(0);
}

void MainWindow::press_ortho()
{
    ui->widget->change_projection(1);
}

void MainWindow::press_background_color()
{
    ui->widget->mas_color[0] = ui->doubleSpinBox_red->value();
    ui->widget->mas_color[1] = ui->doubleSpinBox_green->value();
    ui->widget->mas_color[2] = ui->doubleSpinBox_blue->value();

    ui->widget->update();
}

void MainWindow::press_edge()
{
    ui->widget->mas_color_edges[0] = ui->doubleSpinBox_red_edge->value();
    ui->widget->mas_color_edges[1] = ui->doubleSpinBox_green_edge->value();
    ui->widget->mas_color_edges[2] = ui->doubleSpinBox_blue_edge->value();
    ui->widget->width_edges = ui->doubleSpinBox_width_edge->value();
    if (ui->checkBox_dotted_line->isChecked()) {
        ui->widget->flag_dotted_line = 1;
    } else if (!ui->checkBox_dotted_line->isChecked()) {
        ui->widget->flag_dotted_line = 0;
    }
    ui->widget->update();
}

void MainWindow::press_point()
{
    ui->widget->mas_color_points[0] = ui->doubleSpinBox_red_point->value();
    ui->widget->mas_color_points[1] = ui->doubleSpinBox_green_point->value();
    ui->widget->mas_color_points[2] = ui->doubleSpinBox_blue_point->value();
    ui->widget->size_point = ui->doubleSpinBox_point_size->value();
    if (ui->radioButton_missing->isChecked()) {
        ui->widget->flag_draw_point = 0;
    } else if (ui->radioButton_circle->isChecked()) {
        ui->widget->flag_draw_point = 1;
    } else if (ui->radioButton_square->isChecked()) {
        ui->widget->flag_draw_point = 2;
    }
    ui->widget->update();
}

void MainWindow::press_save()
{
    QString file = QFileDialog::getSaveFileName(this, "Save as...", "name", "BMP (*.bmp);; JPEG (*.jpeg)");
    ui->widget->grab().save(file);
}

void MainWindow::press_start_screencast()
{
    flag_record = 1;
}

void MainWindow::press_stop_screencast()
{
    flag_record = 0;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save screenshot"), "", tr("GIF screenshot (*.gif);;GIF screenshot (*.gif)"));
    QGifImage gif(QSize(640, 480));
    QVector<QRgb> ctable;
    ctable << qRgb(255, 255, 255)
           << qRgb(0, 0, 0)
           << qRgb(255, 0, 0)
           << qRgb(0, 255, 0)
           << qRgb(0, 0, 255)
           << qRgb(255, 255, 0)
           << qRgb(0, 255, 255)
           << qRgb(255, 0, 255);

    gif.setGlobalColorTable(ctable, Qt::black);
    gif.setDefaultTransparentColor(Qt::black);
    gif.setDefaultDelay(100);

    for (QVector<QImage>::Iterator img = mas_image.begin(); img != mas_image.end(); ++img) {
        gif.addFrame(*img);
    }
    gif.save(fileName);
}

void MainWindow::create_screen()
{
    if (flag_record == 1) {
        mas_image.push_back(ui->widget->grab().toImage());
    }
}

void MainWindow::write()
{
    char proection = ui->widget->flag + '0';
    fputc(proection, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);

    QString qstr_back_red = QString::number(ui->widget->mas_color[0]);
    char* str_back_red = new char[qstr_back_red.length()];
    QByteArray barr_back_red = qstr_back_red.toLatin1();
    strlcpy(str_back_red, barr_back_red, qstr_back_red.length() + 1);
    fputs(str_back_red, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_back_red;

    QString qstr_back_green = QString::number(ui->widget->mas_color[1]);
    char* str_back_green = new char[qstr_back_green.length()];
    QByteArray barr_back_green = qstr_back_green.toLatin1();
    strlcpy(str_back_green, barr_back_green, qstr_back_green.length() + 1);
    fputs(str_back_green, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_back_green;

    QString qstr_back_blue = QString::number(ui->widget->mas_color[2]);
    char* str_back_blue = new char[qstr_back_blue.length()];
    QByteArray barr_back_blue = qstr_back_blue.toLatin1();
    strlcpy(str_back_blue, barr_back_blue, qstr_back_blue.length() + 1);
    fputs(str_back_blue, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_back_blue;

    QString qstr_line_red = QString::number(ui->widget->mas_color_edges[0]);
    char* str_line_red = new char[qstr_line_red.length()];
    QByteArray barr_line_red = qstr_line_red.toLatin1();
    strlcpy(str_line_red, barr_line_red, qstr_line_red.length() + 1);
    fputs(str_line_red, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_line_red;

    QString qstr_line_green = QString::number(ui->widget->mas_color_edges[1]);
    char* str_line_green = new char[qstr_line_green.length()];
    QByteArray barr_line_green = qstr_line_green.toLatin1();
    strlcpy(str_line_green, barr_line_green, qstr_line_green.length() + 1);
    fputs(str_line_green, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_line_green;

    QString qstr_line_blue = QString::number(ui->widget->mas_color_edges[2]);
    char* str_line_blue = new char[qstr_line_blue.length()];
    QByteArray barr_line_blue = qstr_line_blue.toLatin1();
    strlcpy(str_line_blue, barr_line_blue, qstr_line_blue.length() + 1);
    fputs(str_line_blue, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_line_blue;

    QString qstr_line_widht = QString::number(ui->widget->width_edges);
    char* str_line_widht = new char[qstr_line_widht.length()];
    QByteArray barr_line_widht = qstr_line_widht.toLatin1();
    strlcpy(str_line_widht, barr_line_widht, qstr_line_widht.length() + 1);
    fputs(str_line_widht, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_line_widht;

    char line_type = ui->widget->flag_dotted_line + '0';
    fputc(line_type, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);

    QString qstr_point_red = QString::number(ui->widget->mas_color_points[0]);
    char* str_point_red = new char[qstr_point_red.length()];
    QByteArray barr_point_red = qstr_point_red.toLatin1();
    strlcpy(str_point_red, barr_point_red, qstr_point_red.length() + 1);
    fputs(str_point_red, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_point_red;

    QString qstr_point_green = QString::number(ui->widget->mas_color_points[1]);
    char* str_point_green = new char[qstr_point_green.length()];
    QByteArray barr_point_green = qstr_point_green.toLatin1();
    strlcpy(str_point_green, barr_point_green, qstr_point_green.length() + 1);
    fputs(str_point_green, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_point_green;

    QString qstr_point_blue = QString::number(ui->widget->mas_color_points[2]);
    char* str_point_blue = new char[qstr_point_blue.length()];
    QByteArray barr_point_blue = qstr_point_blue.toLatin1();
    strlcpy(str_point_blue, barr_point_blue, qstr_point_blue.length() + 1);
    fputs(str_point_blue, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_point_blue;

    QString qstr_point_size = QString::number(ui->widget->size_point);
    char* str_point_size = new char[qstr_point_size.length()];
    QByteArray barr_point_size = qstr_point_size.toLatin1();
    strlcpy(str_point_size, barr_point_size, qstr_point_size.length() + 1);
    fputs(str_point_size, ui->widget->file_for_write);
    fputc('\n', ui->widget->file_for_write);
    delete[] str_point_size;

    char point_type = ui->widget->flag_draw_point + '0';
    fputc(point_type, ui->widget->file_for_write);
}
