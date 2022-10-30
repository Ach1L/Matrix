#pragma once
#include "Vector.h"
const int MAX_TAPEMATRIX_SIZE = 10000;
template<typename T>
class TTapeMatrix : public TDynamicVector<TDynamicVector<T>>
{
protected:
  int rad;//number of non-zero diagonals = radius * 2 - 1
  // d c e 0 0
  // b d c e 0
  // a b d c e , r = 3, r = {a, b, d or d, c, e}
  // 0 a b d c
  // 0 0 a b d
public:
  TTapeMatrix(int size = 3, int radius = 2);
  virtual ~TTapeMatrix();
  TTapeMatrix<T>& operator*(const TTapeMatrix<T>& p);
  TTapeMatrix<T> operator+(const TTapeMatrix<T>& p);
  TTapeMatrix<T> operator-(const TTapeMatrix<T>& p);

  template<typename T>
  friend std::istream& operator>>(std::istream& istr, TTapeMatrix<T>& v);
  template<typename T>
  friend std::ostream& operator<<(std::ostream& ostr, const TTapeMatrix<T>& v);
};

template<typename T>
inline TTapeMatrix<T>::TTapeMatrix(int size, int radius)
{
  if (radius < 1)//if radius = 0, then this is null matrix
    throw "Radius < 1";
  if (radius >= size)//if the radius is equal to the size, then this is an ordinary matrix and there is no point in considering it here
    throw "Radius >= size";
  if (size < 1)
    throw "size < 1";
  if (size > MAX_TAPEMATRIX_SIZE)
    throw "size > MAX_TAPEMATRIX_SIZE";
  pMem = new TDynamicVector<T>[radius * 2 - 1];
  sz = size;
  rad = radius;
  int a = 1, b = 0;
  for (int i = 0; i < rad * 2 - 1; i++)
  {
    b = sz - rad + a;
    pMem[i] = TDynamicVector<T>(b);
    if (rad - 1 > i)
      a++;
    else
      a--;
  }
}

template<typename T>
inline TTapeMatrix<T>::~TTapeMatrix(){}

template<typename T>
inline TTapeMatrix<T>& TTapeMatrix<T>::operator*(const TTapeMatrix<T>& p)
{
 /* if (p.sz != this->sz)
    throw "operator* : p.sz != this->sz";
  if (p.rad != this->rad)
    throw "p.rad != this->rad";
  TTapeMatrix<T> res(p.sz, p.rad);
  for (int i = 0; i < 2 * p.rad - 1; i++)
  {
    for (int j = 0; j < p.sz; j++)
    {
      res[i][j] = 0;
      for (int k = p.rad - 1, l = p.rad - 1; k < ; l++, k--)
      {
        res[i][j] += p[k][i] * (*this)[l][j];
      }

    }
  }*/
}

template<typename T>
inline TTapeMatrix<T> TTapeMatrix<T>::operator+(const TTapeMatrix<T>& p)
{
  if (sz != p.sz)
    throw "operator+ : sz != p.sz";
  int c = p.rad + this->rad - 1;
  if (p.rad > this->rad)
  {
    int k = p.sz - p.rad + 1;
    TTapeMatrix<T> res(p.sz, p.rad);
    for (int b = 0, i = p.rad - this->rad; i < c; i++, b++)
    {
      for (int j = 0; j < k + 1; j++)
        res[i][j] = p[i][j] + (*this)[b][j];
      if (i < p.rad - 1)
        k++;
      else
        k--;
    }
    for (int i = 0; i < p.rad - this->rad; i++)
      res[i] = p[i];
    for (int i = c; i < p.rad * 2 - 1; i++)
      res[i] = p[i];
    return res;
  }
  else
  {
    int k = this->sz - this->rad + 1;
    TTapeMatrix<T> res(this->sz, this->rad);
    for (int i = this->rad - p.rad, b = 0; i < c; i++, b++)
    {
      for (int j = 0; j < k + 1; j++)
        res[i][j] = p[b][j] + (*this)[i][j];
      if (i < this->rad - 1)
        k++;
      else
        k--;
    }
    for (int i = 0; i < this->rad - p.rad; i++)
      res[i] = (*this)[i];
    for (int i = c; i < this->rad * 2 - 1; i++)
      res[i] = (*this)[i];
    return res;
  }
}

template<typename T>
inline TTapeMatrix<T> TTapeMatrix<T>::operator-(const TTapeMatrix<T>& p)
{
  if (sz != p.sz)
    throw "operator+ : sz != p.sz";
  int  c = p.rad + this->rad - 1;
  if (p.rad > this->rad)
  {
    int k = p.sz - p.rad + 1;
    TTapeMatrix<T> res(p.sz, p.rad);
    for (int b = 0, i = p.rad - this->rad; i < c; i++, b++)
    {
      for (int j = 0; j < k + 1; j++)
        res[i][j] = p.pMem[i][j] - (*this)[b][j];
      if (i < p.rad - 1)
        k++;
      else
        k--;
    }
    for (int i = 0; i < p.rad - this->rad; i++)
      res[i] = p[i];
    for (int i = c; i < p.rad * 2 - 1; i++)
      res[i] = p[i];
    return res;
  }
  else
  {
    int k = this->sz - this->rad + 1;
    TTapeMatrix<T> res(this->sz, this->rad);
    for (int i = this->rad - p.rad, b = 0; i < c; i++, b++)
    {
      for (int j = 0; j < k + 1; j++)
        res[i][j] = p.pMem[b][j] - (*this)[i][j];
      if (i < this->rad - 1)
        k++;
      else
        k--;
    }
    for (int i = 0; i < this->rad - p.rad; i++)
      res[i] = (*this)[i];
    for (int i = c; i < this->rad * 2 - 1; i++)
      res[i] = (*this)[i];
    return res;
  }
}

template<typename T>
inline std::istream& operator>>(std::istream& istr, TTapeMatrix<T>& v)
{
  int i = 0, k = 0, j = 0, b = 0;
  int* o = new int[v.rad];
  for (; j < v.rad; j++)
  {
    for (i = 0; i < v.sz; i++)
    {
      istr >> v[v.rad - j + i - 1][k];
      if (k < j)
        k++;
      b = v.rad - j + i;
      if (b == v.rad * 2 - 1)
        break;
    }
    if (i != v.sz - 1)
      o[j] = i+1;
    k = 0;
  }
  int c = v.sz - v.rad - 1;
  if (c == 0)
    c = 1;
  if (c <= 2 && (v.sz != 5 || v.rad != 2))
  {
    if (c == 2)
      c = 1;
    k = 1;
    for (j = v.sz - v.rad - 1; j > -1; j--)
    {
      for (i = 0; i < o[j]; i++)
      {
        istr >> v[i][k];
        if (i < v.rad - 1)
          k++;
      }
      c++;
      k = c;
    }
  }
  else
  {
    k = 1;
    for (j = v.sz - v.rad; j > 0; j--)
    {
      for (i = 0; i < v.sz - c; i++)
      {
        istr >> v[i][k];
        if (i < v.rad - 1)
          k++;
      }
      if (j - 1 == 1)
        c++;
    }
  }
  return istr;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& ostr, const TTapeMatrix<T>& v)
{
  int i = 0, k = 0, j = 0, b = 0;
  int* o = new int[v.rad];
  for (; j < v.rad; j++)
  {
    for (i = 0; i < v.sz; i++)
    {
      ostr << v[v.rad - j + i - 1][k] << ' ';
      if (k < j)
        k++;
      b = v.rad - j + i;
      if (b == v.rad * 2 - 1)
        break;
    }
    if (i != v.sz - 1)
      o[j] = i + 1;
    ostr << std::endl;
    k = 0;
  }
  int c = v.sz - v.rad - 1;
  if (c == 0)
    c = 1;
  if (c <= 2 && (v.sz != 5 || v.rad != 2))
  {
    if (c == 2)
      c = 1;
    k = 1;
    for (j = v.sz - v.rad - 1; j > -1; j--)
    {
      for (int a = 0; a < k; a++)
        ostr << 0 << ' ';
      for (i = 0; i < o[j]; i++)
      {
        ostr << v[i][k] << ' ';
        if (i < v.rad - 1)
          k++;
      }
      ostr << std::endl;
      c++;
      k = c;
    }
  }
  else 
  {
    k = 1;
    for (j = v.sz - v.rad; j > 0; j--)
    {
      for (int a = 0; a < k; a++)
        ostr << 0 << ' ';
      for (i = 0; i < v.sz - c; i++)
      {
        ostr << v[i][k] << ' ';
        if (i < v.rad - 1)
          k++;
      }
      ostr << std::endl;
      if (j - 1 == 1)
        c++;
    }
  }
  return ostr;
}
