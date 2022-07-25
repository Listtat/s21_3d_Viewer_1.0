#include "s21_3D_Viewer_1.0.h"

/**
 * Вызов парсеров
 * @return 0 - OK
 * @return 1 - ERROR
 */
int s21_3d(my_data* main_struct, char* path_to_file) {
    int error_code = 0;
    error_code = s21_parse_count(main_struct, path_to_file);
    if (!error_code) {
        error_code = s21_parse_data(main_struct, path_to_file);
    }
    return error_code;
}

/**
 * Парсер количества вершин и полигонов
 * @return 0 - OK
 * @return 1 - ERROR
 */
int s21_parse_count(my_data* main_struct, char* path_to_file) {
    int error_code = 0;
    FILE *file;
    file = fopen(path_to_file, "r");

    if (file != NULL) {
        char *str = NULL;
        size_t len = 0;
        unsigned int count_vertexes = 0;
        unsigned int count_facets = 0;
        while (getline(&str, &len, file) != -1) {
            if (str[0] == 'v' && str[1] == ' ') {
                count_vertexes++;
            } else if (str[0] == 'f') {
                count_facets++;
            }
        }
        main_struct->count_of_vertexes = count_vertexes;
        main_struct->count_of_facets = count_facets;
        free(str);
        fclose(file);
    } else {
        error_code = 1;
    }
    return error_code;
}

/**
 * Парсер координат вершин и данных для полигонов
 * @return 0 - OK
 * @return 1 - ERROR
 */
int s21_parse_data(my_data* main_struct, char* path_to_file) {
    int error_code = 0;
    matrix_t matrix_of_vertexes;
    error_code = s21_create_matrix(main_struct->count_of_vertexes + 1, 3, &matrix_of_vertexes);
    if (!error_code) {
        main_struct->matrix_3d = matrix_of_vertexes;

        main_struct->polygons = malloc((main_struct->count_of_facets + 1) * sizeof(polygon_t));

        FILE *file;
        file = fopen(path_to_file, "r");
        if (file != NULL) {
            char *str = NULL;
            size_t len = 0;
            int index = 1;
            int j = 1;
            while (getline(&str, &len, file) != -1) {
                if (str[0] == 'v' && str[1] == ' ') {
                    s21_fill_matrix(main_struct, &index, str);
                } else if (str[0] == 'f') {
                    main_struct->polygons[j].numbers_of_vertexes_in_facets =
                            s21_find_count_vertexes_for_connect(str);
                    main_struct->polygons[j].vertexes = calloc(main_struct->polygons[j].
                            numbers_of_vertexes_in_facets, sizeof(unsigned int));
                    s21_fill_mas_of_vertexes(str, main_struct, j);
                    j++;
                }
            }
            free(str);
            fclose(file);
        } else {
            error_code = 1;
        }
    }
    return error_code;
}

/**
 * Парсер количества полигонов в спаршенной строке
 * @return count_vertexes
 */
unsigned int s21_find_count_vertexes_for_connect(char* str) {
    int i = 0;
    unsigned int count_vertexes = 0;
    while (1) {
        for (; (str[i] != ' ') && (str[i] != '\0'); i++) {}
        if (str[i] == '\0' || (str[i] == ' ' && (str[i + 1] < 48 || str[i + 1] > 57))) {
            break;
        }
        i++;
        count_vertexes++;
    }
    return count_vertexes;
}

/**
 * Заполнение матрицы координатами вершин
 */
void s21_fill_matrix(my_data* main_struct, int* index, char* str) {
    int m = 2;
    for (int i = 0; i < 3; i++) {
        char str1[256];
        memset(str1, '\0', 256);
        int k = 0;
        while (1) {
            if (str[m] == ' ' || str[m] == '\0') {
                main_struct->matrix_3d.matrix[*index][i] = atof(str1);
                break;
            } else {
                str1[k] = str[m];
                k++;
                m++;
            }
        }
        m++;
    }
    (*index)++;
}

/**
 * Заполнение данных о полигонах
 */
void s21_fill_mas_of_vertexes(char* str, my_data* main_struct, int index) {
    int i = 0;
    int j = 0;
    while (1) {
        for (; (str[j] != ' ') && (str[j] != '\0'); j++) {}
        if (str[j] == '\0') {
            break;
        }
        j++;
        char str1[256];
        memset(str1, '\0', 256);
        int k = 0;
        for (; str[j] != '/' && str[j] != ' ' && str[j] != '\0'; j++, k++) {
            str1[k] = str[j];
        }
        main_struct->polygons[index].vertexes[i] = atoi(str1);
        i++;
    }
}


/**
 * Аффинный сдвиг
 */
void s21_shift(my_data* main_struct, double* coord_shifts) {
    for (unsigned int i = 1; i < main_struct->matrix_3d.rows; i++) {
        for (unsigned int j = 0; j < main_struct->matrix_3d.columns; j++) {
            main_struct->matrix_3d.matrix[i][j] += coord_shifts[j];
        }
    }
}

/**
 * Аффинный поворот по оси X
 */
void s21_rotate_x(my_data* main_struct, double angular) {
    matrix_t result;
    matrix_t rotation_matrix;
    matrix_t point_matrix;
    s21_create_matrix(3, 3, &rotation_matrix);
    rotation_matrix.matrix[0][0] = 1;
    rotation_matrix.matrix[0][1] = 0;
    rotation_matrix.matrix[0][2] = 0;

    rotation_matrix.matrix[1][0] = 0;
    rotation_matrix.matrix[1][1] = cos(angular);
    rotation_matrix.matrix[1][2] = sin(angular);

    rotation_matrix.matrix[2][0] = 0;
    rotation_matrix.matrix[2][1] = -sin(angular);
    rotation_matrix.matrix[2][2] = cos(angular);

    for (unsigned int i = 1; i < main_struct->matrix_3d.rows; i++) {
        s21_create_matrix(3, 1, &point_matrix);
        point_matrix.matrix[0][0] = main_struct->matrix_3d.matrix[i][0];
        point_matrix.matrix[1][0] = main_struct->matrix_3d.matrix[i][1];
        point_matrix.matrix[2][0] = main_struct->matrix_3d.matrix[i][2];
        s21_mult_matrix(&rotation_matrix, &point_matrix, &result);

        main_struct->matrix_3d.matrix[i][0] = result.matrix[0][0];
        main_struct->matrix_3d.matrix[i][1] = result.matrix[1][0];
        main_struct->matrix_3d.matrix[i][2] = result.matrix[2][0];
        s21_remove_matrix(&point_matrix);
    }
    s21_remove_matrix(&result);
    s21_remove_matrix(&rotation_matrix);
}

/**
 * Аффинный поворот по оси Y
 */
void s21_rotate_y(my_data* main_struct, double angular) {
    matrix_t result;
    matrix_t rotation_matrix;
    matrix_t point_matrix;
    s21_create_matrix(3, 3, &rotation_matrix);
    rotation_matrix.matrix[0][0] = cos(angular);
    rotation_matrix.matrix[0][1] = 0;
    rotation_matrix.matrix[0][2] = -sin(angular);

    rotation_matrix.matrix[1][0] = 0;
    rotation_matrix.matrix[1][1] = 1;
    rotation_matrix.matrix[1][2] = 0;

    rotation_matrix.matrix[2][0] = sin(angular);
    rotation_matrix.matrix[2][1] = 0;
    rotation_matrix.matrix[2][2] = cos(angular);

    for (unsigned int i = 1; i < main_struct->matrix_3d.rows; i++) {
        s21_create_matrix(3, 1, &point_matrix);
        point_matrix.matrix[0][0] = main_struct->matrix_3d.matrix[i][0];
        point_matrix.matrix[1][0] = main_struct->matrix_3d.matrix[i][1];
        point_matrix.matrix[2][0] = main_struct->matrix_3d.matrix[i][2];
        s21_mult_matrix(&rotation_matrix, &point_matrix, &result);

        main_struct->matrix_3d.matrix[i][0] = result.matrix[0][0];
        main_struct->matrix_3d.matrix[i][1] = result.matrix[1][0];
        main_struct->matrix_3d.matrix[i][2] = result.matrix[2][0];
        s21_remove_matrix(&point_matrix);
    }
    s21_remove_matrix(&result);
    s21_remove_matrix(&rotation_matrix);
}

/**
 * Аффинный поворот по оси Z
 */
void s21_rotate_z(my_data* main_struct, double angular) {
    matrix_t result;
    matrix_t rotation_matrix;
    matrix_t point_matrix;
    s21_create_matrix(3, 3, &rotation_matrix);
    rotation_matrix.matrix[0][0] = cos(angular);
    rotation_matrix.matrix[0][1] = sin(angular);
    rotation_matrix.matrix[0][2] = 0;

    rotation_matrix.matrix[1][0] = -sin(angular);
    rotation_matrix.matrix[1][1] = cos(angular);
    rotation_matrix.matrix[1][2] = 0;

    rotation_matrix.matrix[2][0] = 0;
    rotation_matrix.matrix[2][1] = 0;
    rotation_matrix.matrix[2][2] = 1;

    for (unsigned int i = 1; i < main_struct->matrix_3d.rows; i++) {
        s21_create_matrix(3, 1, &point_matrix);
        point_matrix.matrix[0][0] = main_struct->matrix_3d.matrix[i][0];
        point_matrix.matrix[1][0] = main_struct->matrix_3d.matrix[i][1];
        point_matrix.matrix[2][0] = main_struct->matrix_3d.matrix[i][2];
        s21_mult_matrix(&rotation_matrix, &point_matrix, &result);

        main_struct->matrix_3d.matrix[i][0] = result.matrix[0][0];
        main_struct->matrix_3d.matrix[i][1] = result.matrix[1][0];
        main_struct->matrix_3d.matrix[i][2] = result.matrix[2][0];
        s21_remove_matrix(&point_matrix);
    }
    s21_remove_matrix(&result);
    s21_remove_matrix(&rotation_matrix);
}

/**
 * Аффинное масштабирование
 */
void s21_scaling(my_data* main_struct, double scale) {
    matrix_t result;
    matrix_t point_matrix;

    for (unsigned int i = 1; i < main_struct->matrix_3d.rows; i++) {
        s21_create_matrix(3, 1, &point_matrix);
        point_matrix.matrix[0][0] = main_struct->matrix_3d.matrix[i][0];
        point_matrix.matrix[1][0] = main_struct->matrix_3d.matrix[i][1];
        point_matrix.matrix[2][0] = main_struct->matrix_3d.matrix[i][2];
        s21_mult_number(&point_matrix, scale, &result);

        main_struct->matrix_3d.matrix[i][0] = result.matrix[0][0];
        main_struct->matrix_3d.matrix[i][1] = result.matrix[1][0];
        main_struct->matrix_3d.matrix[i][2] = result.matrix[2][0];
        s21_remove_matrix(&point_matrix);
    }

    s21_remove_matrix(&result);
}

/**
 * Создание матрицы
 */
int s21_create_matrix(unsigned int rows, unsigned int columns, matrix_t *result) {
    int error_code = OK;

    result->rows = rows;
    result->columns = columns;

    // Если создание матрицы физически возможно, то создаем
    if (rows > 0 && columns > 0) {
        result->matrix = calloc(result->rows, sizeof(double *));
        if (result->matrix != NULL) {
            for (unsigned int i = 0; i < result->rows; i++) {
                result->matrix[i] = calloc(result->columns, sizeof(double));
                if (result->matrix[i] == NULL) {
                    error_code = INCORRECT_MATRIX;
                    break;
                }
            }
        } else {
            error_code = INCORRECT_MATRIX;
        }
    } else {
        result->matrix = NULL;
        error_code = INCORRECT_MATRIX;
    }
    return error_code;
}

/**
 * Умножение матриц
 * @return 0 - ОК
 * @return 1 - Ошибка, некорректная матрица
 * @return 2 - Ошибка вычисления
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int error_code = OK;

    // Проверка на корректность матриц
    if (!s21_check_matrix(A) && !s21_check_matrix(B)) {
        // Проверка на возможность вычисления
        if (A->columns == B->rows) {
            error_code = s21_create_matrix(A->rows, B->columns, result);
            if (error_code == OK) {
                for (unsigned int i = 0; i < A->rows; i++) {
                    for (unsigned int j = 0; j < B->columns; j++) {
                        for (unsigned int k = 0; k < B->rows; k++) {
                            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                        }
                    }
                }
            }
        } else {
            error_code = CALC_ERROR;
        }
    } else {
        error_code = INCORRECT_MATRIX;
    }
    return error_code;
}

/**
 * Умножение матрицы на число
 * @return 0 - ОК
 * @return 1 - Ошибка, некорректная матрица
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int error_code = OK;

    // Проверка на корректность матрицы
    if (A != NULL && s21_check_matrix(A) == OK) {
        error_code = s21_create_matrix(A->rows, A->columns, result);
        if (error_code == OK) {
            for (unsigned int i = 0; i < A->rows; i++) {
                for (unsigned int j = 0; j < A->columns; j++) {
                    result->matrix[i][j] = A->matrix[i][j] * number;
                }
            }
        }
    } else {
        error_code = INCORRECT_MATRIX;
    }

    return error_code;
}

/**
 * Проверка матрицы на корректность
 * @return 0 - OK
 * @return 1 - INCORRECT_MATRIX
 */
int s21_check_matrix(matrix_t *A) {
    int error_code = OK;

    if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
        error_code = INCORRECT_MATRIX;
    }

    return error_code;
}

// Очистка матриц
void s21_remove_matrix(matrix_t *A) {
    if (A->matrix) {
        for (unsigned int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
        }
        free(A->matrix);
        A->rows = 0;
        A->columns = 0;
        A = NULL;
    }
}
