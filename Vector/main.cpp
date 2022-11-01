#include "Vector.h"
#include "Matrix.h"
#include "TrMatrix.h"
#include "TapeMatrix.h"
#include <iostream>
int main()
{
  //Vector
  TDynamicVector<int> a(5);
  TDynamicVector<int> p(5);
  TDynamicVector<int> u(5);
  std::cin >> a;//1 2 3 4 5
  for (int i = 0; i < 5; i++)
    p[i] = i + 3;
  u = a + p;
  std::cout << u << std::endl;

  //Vector iterator
  for (auto i = u.begin(); i != u.end(); ++i)
    std::cout << *i << ' ';
  std::cout << std::endl;

  //Matrix
  TDynamicMatrix<int> F(5);
  TDynamicMatrix<int> D(5);
  TDynamicMatrix<int> M(5);
  std::cin >> F;//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      M[i][j] = i + j + 3;
  D = F * M;
  std::cout << D;
  std::cout << std::endl;

  //Triangle matrix
  TTrMatrix<int> N(5);
  TTrMatrix<int> V(5);
  TTrMatrix<int> C(5);
  std::cin >> N;//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      if (i >= j)
        V[i][j] = i + j - 1;
  C = (N - V) * V;
  std::cout << C;
  std::cout << std::endl;

  //Tape matrix
  TTapeMatrix<int> G(5, 3);
  TTapeMatrix<int> H(5, 2);
  TTapeMatrix<int> J(5, 3);
  TTapeMatrix<int> Y(G);
  TTapeMatrix<int> L(6, 3);
  int i = 0, k = 0, j = 0, b = 0;
  int* o = new int[3];
  for (; j < 3; j++)
  {
    for (i = 0; i < 5; i++)
    {
      G[3 - j + i - 1][k] = i + j - k;
      if (k < j)
        k++;
      b = 3 - j + i;
      if (b == 3 * 2 - 1)
        break;
    }
    if (i != 5 - 1)
      o[j] = i + 1;
    k = 0;
  }
  int c = 5 - 3 - 1;
  if (c == 0)
    c = 1;
  if (c == 2)
    c = 1;
  k = 1;
  for (j = 5 - 3 - 1; j > -1; j--)
  {
    for (i = 0; i < o[j]; i++)
    {
      G[i][k] = i + k - j;
      if (i < 3 - 1)
        k++;
    }
    c++;
    k = c;
  }
  std::cin >> H;//1 2 3 4 5 6 7 8 9 10 11 12 13
  std::cout << H << std::endl;
  J = H + G;
  std::cout << J << std::endl;
  J = G;
  std::cout << J << std::endl;

  std::cin >> L;//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
  J = L;
  std::cout << J;
  return 0;
}