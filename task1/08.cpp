// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Поиск столбца с наибольшей суммой элементов

#include <iostream>

using namespace std;

int column_sum(int** mtrx, int* sum_arr, int n, int m)
{
  int max_sum = -1e9;
  int max_column_number = -1;
  
  for (int j = 0; j < m; ++j)
  {
    for (int i = 0; i < n; ++i)
    {
      sum_arr[j] += mtrx[i][j];
    }
    if (sum_arr[j] > max_sum)
    {
      max_sum = sum_arr[j];
      max_column_number = j;
    }
  }

  return max_column_number;
}

//------------------------------------------------------------------------------

int main()
{
  int n,m;
  cin >> n; // число строк
  cin >> m; // число столбцов

  int** matrix = new int*[n];
  for (int i = 0; i < n; i++)
    matrix[i] = new int [m];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> matrix[i][j]; // ввели матрицу

  int* sum_arr = new int[m];

  cout << column_sum(matrix, sum_arr, n, m) << endl;


  delete[] matrix;
  delete[] sum_arr;
  return 0;
}
