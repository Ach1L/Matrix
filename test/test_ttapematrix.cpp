//#include "TapeMatrix.h"
//#include <gtest.h>
//
//TEST(TTapeMatrix, can_create_matrix_with_positive_length)
//{
//  ASSERT_NO_THROW(TTapeMatrix<int> m(5));
//}
//
//TEST(TTapeMatrix, cant_create_too_large_matrix)
//{
//  ASSERT_ANY_THROW(TTapeMatrix<int> m(MAX_TAPEMATRIX_SIZE + 1));
//}
//
//TEST(TTapeMatrix, cant_create_matrix_with_too_large_radius)
//{
//  ASSERT_ANY_THROW(TTapeMatrix<int> m(5,6));
//}
//
//TEST(TTapeMatrix, cant_create_matrix_with_negative_radius)
//{
//  ASSERT_ANY_THROW(TTapeMatrix<int> m(5, -5));
//}
//
//TEST(TTapeMatrix, throws_when_create_matrix_with_negative_length)
//{
//  ASSERT_ANY_THROW(TTapeMatrix<int> m(-5));
//}
//
//TEST(TTapeMatrix, can_create_copied_matrix)
//{
//  TTapeMatrix<int> m(5,3);
//
//  ASSERT_NO_THROW(TTapeMatrix<int> m1(m));
//}
//
//TEST(TTapeMatrix, copied_matrix_is_equal_to_source_one)
//{
//  TTapeMatrix<int> m1(5, 2);
//  for (int i = 0; i < 5; i++)
//    m1[1][i] = i + 1;
//  for (int i = 0; i < 4; i++)
//  {
//    m1[0][i] = i;
//    m1[2][i] = i + 2;
//  }
//  TTapeMatrix<int> m2(m1);
//  for (int i = 0; i < 5; i++)
//    EXPECT_EQ(m1[1][i], m2[1][i]);
//  for (int i = 0; i < 4; i++)
//  {
//    EXPECT_EQ(m1[0][i], m2[0][i]);
//    EXPECT_EQ(m1[2][i], m2[2][i]);
//  }
//}
//
//TEST(TTapeMatrix, copied_matrix_has_its_own_memory)
//{
//  TTapeMatrix<int>m1(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      m1[i][j] = i + j + 1;
//  TTapeMatrix<int>m2(m1);
//  m2[0][0] = -1;
//  EXPECT_NE(m1[0][0], m2[0][0]);
//}
//
//TEST(TTapeMatrix, can_get_size)
//{
//  TTapeMatrix<int>m(2);
//  EXPECT_EQ(2, m.size());
//}
//
//TEST(TTapeMatrix, can_set_and_get_element)
//{
//  TTapeMatrix<int>m(2);
//  m[1][1] = 5;
//  EXPECT_EQ(5, m[1][1]);
//}
//
//TEST(TTapeMatrix, throws_when_set_element_with_negative_index)
//{
//  TTapeMatrix<int>m(2);
//  ASSERT_ANY_THROW(m.at(1).at(-1));
//  ASSERT_ANY_THROW(m.at(-1).at(1));
//}
//
//TEST(TTapeMatrix, throws_when_set_element_with_too_large_index)
//{
//  TTapeMatrix<int>m(2);
//  ASSERT_ANY_THROW(m.at(1).at(2));
//  ASSERT_ANY_THROW(m.at(2).at(1));
//}
//
//TEST(TTapeMatrix, can_assign_matrix_to_itself)
//{
//  TTapeMatrix<int>m1(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      m1[i][j] = i + j + 1;
//  TTapeMatrix<int>m2(m1);
//  m2 = m2;
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      EXPECT_EQ(m1[i][j], m2[i][j]);
//}
//
//TEST(TTapeMatrix, can_assign_matrices_of_equal_size)
//{
//  TTapeMatrix<int>m1(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      m1[i][j] = i + j + 1;
//  TTapeMatrix<int>m2(2);
//  m2 = m1;
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      EXPECT_EQ(m1[i][j], m2[i][j]);
//}
//
//TEST(TTapeMatrix, assign_operator_change_matrix_size)
//{
//  TTapeMatrix<int>m1(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      m1[i][j] = i + j + 1;
//  TTapeMatrix<int>m2(5);
//  int size = m2.size();
//  m2 = m1;
//  int new_size = m2.size();
//  EXPECT_NE(size, new_size);
//}
//
//TEST(TTapeMatrix, can_assign_matrices_of_different_size)
//{
//  TTapeMatrix<int>m1(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      m1[i][j] = i + j + 1;
//  TTapeMatrix<int>m2(5);
//  m2 = m1;
//  EXPECT_EQ(2, m2.size());
//  for (int i = 0; i < m1.size(); i++)
//    for (int j = 0; j < m1.size(); j++)
//      EXPECT_EQ(m1[i][j], m2[i][j]);
//}
//
//TEST(TTapeMatrix, compare_equal_matrices_return_true)
//{
//  TTapeMatrix<int>m1(2);
//  TTapeMatrix<int>m2(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//    {
//      m1[i][j] = i + j + 1;
//      m2[i][j] = i + j + 1;
//    }
//  EXPECT_EQ(true, m1 == m2);
//}
//
//TEST(TTapeMatrix, compare_matrix_with_itself_return_true)
//{
//  TTapeMatrix<int>m(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      m[i][j] = i + j + 1;
//  EXPECT_EQ(true, m == m);
//}
//
//TEST(TTapeMatrix, matrices_with_different_size_are_not_equal)
//{
//  TTapeMatrix<int>m(2);
//  TTapeMatrix<int>m1(3);
//  EXPECT_EQ(false, m == m1);
//}
//
//TEST(TTapeMatrix, can_add_matrices_with_equal_size)
//{
//  TTapeMatrix<int>m1(2);
//  TTapeMatrix<int>m2(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//    {
//      m1[i][j] = i + j + 1;
//      m2[i][j] = i + j + 2;
//    }
//  TTapeMatrix<int>m3 = m1 + m2;
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      EXPECT_EQ(m1[i][j] + m2[i][j], m3[i][j]);
//}
//
//TEST(TTapeMatrix, cant_add_matrices_with_not_equal_size)
//{
//  TTapeMatrix<int>m1(2);
//  TTapeMatrix<int>m2(3);
//  ASSERT_ANY_THROW(TTapeMatrix<int>m3 = m1 + m2);
//}
//
//TEST(TTapeMatrix, can_subtract_matrices_with_equal_size)
//{
//  TTapeMatrix<int>m1(2);
//  TTapeMatrix<int>m2(2);
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//    {
//      m1[i][j] = i + j + 1;
//      m2[i][j] = i + j + 2;
//    }
//  TTapeMatrix<int>m3 = m2 - m1;
//  for (int i = 0; i < 2; i++)
//    for (int j = 0; j < 2; j++)
//      EXPECT_EQ(m2[i][j] - m1[i][j], m3[i][j]);
//}
//
//TEST(TTapeMatrix, cant_subtract_matrixes_with_not_equal_size)
//{
//  TTapeMatrix<int>m(2);
//  TTapeMatrix<int>m1(3);
//  ASSERT_ANY_THROW(TTapeMatrix<int>m2 = m - m1);
//}