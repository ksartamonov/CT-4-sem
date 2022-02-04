// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Транспонирование квадратной матрицы

#include <iostream>

using namespace std;

int** matrix_transpose (int** mtrx, int n)
{
  int** mtrx_ans = new int*[n];
  for (int i = 0; i < n; i++)
    mtrx_ans[i] = new int [n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        mtrx_ans[i][j] = mtrx[j][i];

  return mtrx_ans;
}

//------------------------------------------------------------------------------

void matrix_print(int** mtrx, int n)
{
  for (int i = 0; i < n; i ++)
  {
    for (int j = 0; j < n; j ++)
      cout << mtrx[i][j] << " ";
    cout << endl;
  }

}

//------------------------------------------------------------------------------

int main ()
{
  int n;
  cin >> n; // размер матрицы

  int** matrix = new int*[n];
  for (int i = 0; i < n; i++)
    matrix[i] = new int [n];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> matrix[i][j]; // ввод элементов матрицы

  matrix = matrix_transpose(matrix,n);

  matrix_print(matrix, n);

  delete[] matrix;

  return 0;
}
