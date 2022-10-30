#include "TapeMatrix.h"
#include <iostream>
int main()
{
  TTapeMatrix<int> G(5, 3);
  TTapeMatrix<int> H(5, 2);
  TTapeMatrix<int> J(5, 3);
  TTapeMatrix<int> Y(G);
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
  std::cout << H;
  J = H + G;
  std::cout << J;
  J = G;
  std::cout << J;
  return 0;
}