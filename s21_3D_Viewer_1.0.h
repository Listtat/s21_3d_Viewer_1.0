#ifndef C8_S21_3D_VIEWER_1_0_H
#define C8_S21_3D_VIEWER_1_0_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Matrix {
    double **matrix;
    unsigned int rows;
    unsigned int columns;
} matrix_t;

typedef struct facets {
    unsigned int* vertexes;
    unsigned int numbers_of_vertexes_in_facets;
} polygon_t;

typedef struct Data {
    unsigned int count_of_vertexes;
    unsigned int count_of_facets;
    matrix_t matrix_3d;
    polygon_t *polygons;
} my_data;

enum {
    OK = 0,
    INCORRECT_MATRIX = 1,
    CALC_ERROR = 2
};

int s21_3d(my_data* main_struct, char* path_to_file);
int s21_parse_count(my_data* main_struct, char* path_to_file);
int s21_parse_data(my_data* main_struct, char* path_to_file);
unsigned int s21_find_count_vertexes_for_connect(char* str);
void s21_fill_matrix(my_data* main_struct, int* index, char* str);
void s21_fill_mas_of_vertexes(char* str, my_data* main_struct, int index);
void s21_shift(my_data* main_struct, double* coord_shifts);
void s21_rotate_x(my_data* main_struct, double angular);
void s21_rotate_y(my_data* main_struct, double angular);
void s21_rotate_z(my_data* main_struct, double angular);
void s21_scaling(my_data* main_struct, double scale);

int s21_create_matrix(unsigned int rows, unsigned int columns, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_check_matrix(matrix_t *A);
void s21_remove_matrix(matrix_t *A);
#endif //C8_S21_3D_VIEWER_1_0_H
