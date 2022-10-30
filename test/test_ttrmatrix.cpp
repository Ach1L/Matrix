#include "TrMatrix.h"

#include <gtest.h>

TEST(TTrMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TTrMatrix<int> m(5));
}

TEST(TTrMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TTrMatrix<int> m(MAX_TRMATRIX_SIZE + 1));
}

TEST(TTrMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TTrMatrix<int> m(-5));
}

TEST(TTrMatrix, can_create_copied_matrix)
{
  TTrMatrix<int> m(5);

  ASSERT_NO_THROW(TTrMatrix<int> m1(m));
}

TEST(TTrMatrix, copied_matrix_is_equal_to_source_one)
{
  TTrMatrix<int>m1(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        m1[i][j] = i + j + 1;
    }
  TTrMatrix<int>m2(m1);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        EXPECT_EQ(m1[i][j], m2[i][j]);
    }
}

TEST(TTrMatrix, copied_matrix_has_its_own_memory)
{
  TTrMatrix<int>m1(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        m1[i][j] = i + j + 1;
    }
  TTrMatrix<int>m2(m1);
  m2[0][0] = -1;
  EXPECT_NE(m1[0][0], m2[0][0]);
}

TEST(TTrMatrix, can_get_size)
{
  TTrMatrix<int>m(2);
  EXPECT_EQ(2, m.size());
}

TEST(TTrMatrix, can_set_and_get_element)
{
  TTrMatrix<int>m(2);
  m[1][1] = 5;
  EXPECT_EQ(5, m[1][1]);
}

TEST(TTrMatrix, throws_when_set_element_with_negative_index)
{
  TTrMatrix<int>m(2);
  ASSERT_ANY_THROW(m.at(1).at(-1));
  ASSERT_ANY_THROW(m.at(-1).at(1));
}

TEST(TTrMatrix, throws_when_set_element_with_too_large_index)
{
  TTrMatrix<int>m(2);
  ASSERT_ANY_THROW(m.at(1).at(2));
  ASSERT_ANY_THROW(m.at(2).at(1));
}

TEST(TTrMatrix, can_assign_matrix_to_itself)
{
  TTrMatrix<int>m1(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        m1[i][j] = i + j + 1;
    }
  TTrMatrix<int>m2(m1);
  m2 = m2;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        EXPECT_EQ(m1[i][j], m2[i][j]);
    }
}

TEST(TTrMatrix, can_assign_matrices_of_equal_size)
{
  TTrMatrix<int>m1(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        m1[i][j] = i + j + 1;
    }
  TTrMatrix<int>m2(2);
  m2 = m1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        EXPECT_EQ(m1[i][j], m2[i][j]);
    }
}

TEST(TTrMatrix, assign_operator_change_matrix_size)
{
  TTrMatrix<int>m1(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        m1[i][j] = i + j + 1;
    }
  TTrMatrix<int>m2(5);
  int size = m2.size();
  m2 = m1;
  int new_size = m2.size();
  EXPECT_NE(size, new_size);
}

TEST(TTrMatrix, can_assign_matrices_of_different_size)
{
  TTrMatrix<int>m1(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        m1[i][j] = i + j + 1;
    }
  TTrMatrix<int>m2(5);
  m2 = m1;
  EXPECT_EQ(2, m2.size());
  for (int i = 0; i < m1.size(); i++)
    for (int j = 0; j < m1.size(); j++)
    {
      if (i >= j)
        EXPECT_EQ(m1[i][j], m2[i][j]);
    }
}

TEST(TTrMatrix, compare_equal_matrices_return_true)
{
  TTrMatrix<int>m1(2);
  TTrMatrix<int>m2(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j) 
      {
        m1[i][j] = i + j + 1;
        m2[i][j] = i + j + 1;
      }
    }
  EXPECT_EQ(true, m1 == m2);
}

TEST(TTrMatrix, compare_matrix_with_itself_return_true)
{
  TTrMatrix<int>m(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        m[i][j] = i + j + 1;
    }
  EXPECT_EQ(true, m == m);
}

TEST(TTrMatrix, matrices_with_different_size_are_not_equal)
{
  TTrMatrix<int>m(2);
  TTrMatrix<int>m1(3);
  EXPECT_EQ(false, m == m1);
}

TEST(TTrMatrix, can_add_matrices_with_equal_size)
{
  TTrMatrix<int>m1(2);
  TTrMatrix<int>m2(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
      {
        m1[i][j] = i + j + 1;
        m2[i][j] = i + j + 2;
      }
    }
  TTrMatrix<int>m3 = m1 + m2;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        EXPECT_EQ(m1[i][j] + m2[i][j], m3[i][j]);
    }
}

TEST(TTrMatrix, cant_add_matrices_with_not_equal_size)
{
  TTrMatrix<int>m1(2);
  TTrMatrix<int>m2(3);
  ASSERT_ANY_THROW(TTrMatrix<int>m3 = m1 + m2);
}

TEST(TTrMatrix, can_subtract_matrices_with_equal_size)
{
  TTrMatrix<int>m1(2);
  TTrMatrix<int>m2(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
      {
        m1[i][j] = i + j + 1;
        m2[i][j] = i + j + 2;
      }
    }
  TTrMatrix<int>m3 = m2 - m1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    {
      if (i >= j)
        EXPECT_EQ(m2[i][j] - m1[i][j], m3[i][j]);
    }
}

TEST(TTrMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TTrMatrix<int>m(2);
  TTrMatrix<int>m1(3);
  ASSERT_ANY_THROW(TTrMatrix<int>m2 = m - m1);
}