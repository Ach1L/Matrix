//#include "TapeMatrix.h"
//#include <gtest.h>
//
//TEST(TTapeMatrix, can_create_matrix_with_positive_length_and_positive_width)
//{
//  ASSERT_NO_THROW(TTapeMatrix<int> m(5, 3));
//}
//
//TEST(TTapeMatrix, cant_create_too_large_matrix)
//{
//  ASSERT_ANY_THROW(TTapeMatrix<int> m(MAX_TAPEMATRIX_SIZE + 1));
//}
//
//TEST(TTapeMatrix, throws_when_create_matrix_with_negative_length_and_negative_width)
//{
//  ASSERT_ANY_THROW(TTapeMatrix<int> m(-5, -3));
//}
//
//TEST(TTapeMatrix, can_create_copied_matrix)
//{
//  TTapeMatrix<int> m(5, 3);
//
//  ASSERT_NO_THROW(TTapeMatrix<int> m1(m));
//}
//
//TEST(TTapeMatrix, copied_matrix_is_equal_to_source_one)
//{
//  TTapeMatrix<int> m(5, 3);
//  m[0][0] = 1;
//  m[1][1] = 2;
//  TTapeMatrix<int> v(m);
//  EXPECT_EQ(1, v[0][0]);
//  EXPECT_EQ(2, v[1][1]);
//  EXPECT_EQ(true, v == m);
//}
//
//TEST(TTapeMatrix, copied_matrix_has_its_own_memory)
//{
//  TTapeMatrix<int> m(5, 3);
//  m[0][0] = 4;
//  TTapeMatrix<int> v(m);
//  int* a = &(m[0][0]);
//  int* b = &(v[0][0]);
//  EXPECT_NE(a, b);
//}
//
//TEST(TTapeMatrix, can_get_size)
//{
//  TTapeMatrix<int> m(5);
//  EXPECT_EQ(5, m.size());
//}
//
//TEST(TTapeMatrix, can_set_and_get_element)
//{
//  TTapeMatrix<int> m(5, 3);
//  ASSERT_NO_THROW(m[0][0] = 4);
//  EXPECT_EQ(4, m[0][0]);
//}
//
//TEST(TTapeMatrix, throws_when_set_element_with_negative_index)
//{
//  TTapeMatrix<int> m(5, 3);
//  ASSERT_ANY_THROW(m.at(-1).at(0));
//}
//
//TEST(TTapeMatrix, throws_when_set_element_with_too_large_index)
//{
//  TTapeMatrix<int> m(5, 3);
//  ASSERT_ANY_THROW(m.at(5).at(0));
//}
//
//TEST(TTapeMatrix, can_assign_matrix_to_itself)
//{
//  TTapeMatrix<int> m(5, 2);
//  m[0][0] = 1;
//  ASSERT_NO_THROW(m = m);
//}
//
//TEST(TTapeMatrix, can_assign_matrices_of_equal_size)
//{
//  TTapeMatrix<int> m(5, 2), v(5, 2);
//  m[0][0] = 4;
//  m[0][1] = 76;
//  v = m;
//  EXPECT_EQ(4, v[0][0]);
//  EXPECT_EQ(76, v[0][1]);
//  v[0][0] = 10;
//  EXPECT_NE(10, m[0][0]);
//}
//
//TEST(TTapeMatrix, assign_operator_change_matrix_size)
//{
//  TTapeMatrix<int> m(5, 2), v(7, 2);
//  m = v;
//  EXPECT_EQ(7, m.size());
//}
//
//TEST(TTapeMatrix, can_assign_matrices_of_different_size)
//{
//  TTapeMatrix<int> m(5), v(7);
//  m[0][0] = 4;
//  m[0][1] = 76;
//  ASSERT_NO_THROW(m = v);
//}
//
//TEST(TTapeMatrix, compare_equal_matrices_return_true)
//{
//  TTapeMatrix<int> m(2), v(2);
//  m[0][0] = 2;
//  v[0][0] = 2;
//  EXPECT_EQ(true, m == v);
//}
//
//TEST(TTapeMatrix, compare_matrix_with_itself_return_true)
//{
//  TTapeMatrix<int> m(2);
//  EXPECT_EQ(true, m == m);
//}
//
//TEST(TTapeMatrix, matrices_with_different_size_are_not_equal)
//{
//  TTapeMatrix<int> m(2), v(3);
//  EXPECT_EQ(false, m == v);
//}
//
//TEST(TTapeMatrix, can_add_matrices_with_equal_size)
//{
//  TTapeMatrix<int> m(5), v(5);
//  m[0][0] = 2;
//  v[0][0] = 2;
//  ASSERT_NO_THROW(m + v);
//  m = m + v;
//  EXPECT_EQ(4, m[0][0]);
//}
//
//TEST(TTapeMatrix, cant_add_matrices_with_not_equal_size)
//{
//  TTapeMatrix<int> m(5), v(7);
//  ASSERT_ANY_THROW(m + v);
//}
//
//TEST(TTapeMatrix, can_subtract_matrices_with_equal_size)
//{
//  TTapeMatrix<int> m(5), v(5);
//  m[0][0] = 2;
//  v[0][0] = 2;
//  ASSERT_NO_THROW(m - v);
//  m = m - v;
//  EXPECT_EQ(0, m[0][0]);
//}
//
//TEST(TTapeMatrix, cant_subtract_matrixes_with_not_equal_size)
//{
//  TTapeMatrix<int> m(5), v(7);
//  ASSERT_ANY_THROW(m - v);
//}
//
//TEST(TTapeMatrix, can_output_lent_matrixes_in_normal_form)
//{
//  std::cout << std::endl;
//  TTapeMatrix<int> g(7, 3);
//  g[0][0] = 4; g[0][1] = 8; g[0][2] = 9; g[0][3] = 6; g[0][4] = 5;
//  g[1][0] = 7; g[1][1] = 8; g[1][2] = 6; g[1][3] = 5; g[1][4] = 4; g[1][5] = 3;
//  g[2][0] = 1; g[2][1] = 2; g[2][2] = 3; g[2][3] = 4; g[2][4] = 5; g[2][5] = 6; g[2][6] = 7;
//  g[3][0] = 7; g[3][1] = 6; g[3][2] = 8; g[3][3] = 3; g[3][4] = 2; g[3][5] = 6;
//  g[4][0] = 3; g[4][1] = 7; g[4][2] = 2; g[4][3] = 1; g[4][4] = 4;
//
//  std::cout << g;
//}