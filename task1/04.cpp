// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Транспонирование матрицы

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

int main()
{
  int n,m;
  cin >> n; // число строк
  cin >> m; // число столбцов

  int** matrix = new int*[n];
  for (int i = 0; i < n; ++i)
  {
    matrix[i] = new int [m];
    for (int j = 0; j < m; ++j)
      cin >> matrix[i][j]; // ввод элементов матрицы
  }

  for (int j = 0; j < m; ++j)
  {
    for (int i = 0; i < n; ++i)
      cout << matrix[i][j] << " ";
    cout << endl;
  }

  delete[] matrix;
  return 0;
}
