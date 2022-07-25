#include "s21_3D_Viewer_1.0.h"
#include <check.h>

START_TEST(parser_test) {
    my_data data;
    int r1 = s21_3d(&data, "NoSuchFile.txt");
    ck_assert_int_eq(r1, 1);
    int r2 = s21_3d(&data, "objects/cub.obj");
    ck_assert_int_eq(r2, 0);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][0], 1.0, 1e-6);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[2][2], 1.0, 1e-6);
}
END_TEST

START_TEST(affinity_test) {
    my_data data;
    s21_3d(&data, "objects/cub.obj");
    double coord_shifts[3] = {0.123, -0.123, 0.123};
    double x_before_move = data.matrix_3d.matrix[1][0];
    double y_before_move = data.matrix_3d.matrix[1][1];
    double z_before_move = data.matrix_3d.matrix[1][2];

    s21_shift(&data, coord_shifts);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][0], x_before_move + 0.123, 1e-6);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][1], y_before_move - 0.123, 1e-6);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][2], z_before_move + 0.123, 1e-6);

    double x_before_rot = data.matrix_3d.matrix[1][0];
    double y_before_rot = data.matrix_3d.matrix[1][1];
    double z_before_rot = data.matrix_3d.matrix[1][2];
    s21_rotate_x(&data, 6.2831853);
    s21_rotate_y(&data, 6.2831853);
    s21_rotate_z(&data, 6.2831853);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][0], x_before_rot, 1e-6);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][1], y_before_rot, 1e-6);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][2], z_before_rot, 1e-6);

    double x_before_zoom = data.matrix_3d.matrix[1][0];
    double y_before_zoom = data.matrix_3d.matrix[1][1];
    double z_before_zoom = data.matrix_3d.matrix[1][2];
    s21_scaling(&data, 1.21);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][0], x_before_zoom * 1.21, 1e-6);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][1], y_before_zoom * 1.21, 1e-6);
    ck_assert_double_eq_tol(data.matrix_3d.matrix[1][2], z_before_zoom * 1.21, 1e-6);
}
END_TEST


int main() {
    Suite *s1 = suite_create("Core");
    TCase *s21_test = tcase_create("Test");
    SRunner *sr = srunner_create(s1);
    suite_add_tcase(s1, s21_test);

    tcase_add_test(s21_test, parser_test);
    tcase_add_test(s21_test, affinity_test);


    srunner_run_all(sr, CK_VERBOSE);
    int errors = srunner_ntests_failed(sr);
    srunner_free(sr);

    return errors == 0 ? 0 : 1;
}
