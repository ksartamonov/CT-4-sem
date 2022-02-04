// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Найти определенное количество наибольших элементов массива и вывести их в порядке возрастания

#include <iostream>
#include <utility>

using namespace std;

void arr_sort(int* arr, bool* select_arr, int n, int m)
{
  for (int i = 0; i < m; ++i)
  {
		int cur_idx = 0;
		int max = -1e9; // Сначала инициализируем максимум очень малым числом

		for (int j = 0; j < n; ++j) {
			if (arr[j] > max && !select_arr[j]) {
				max = arr[j];
				cur_idx = j;
			}
		}
		select_arr[cur_idx] = true; // если число входит в m максимумов
	}
}

//------------------------------------------------------------------------------

int main()
{
  int n; // количество элементов массива
  cin >> n;

  int* arr = new int[n];
  bool* select_arr = new bool[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i]; // считали массив
    select_arr[i] = false;
  }

  int m; // количество максимумов
  cin >> m;
  // отстортируем массив и выведем последние m элементов

  arr_sort(arr, select_arr, n, m);

  for (int i = 0; i < n; i ++)
  {
    if (select_arr[i] == true)
      cout << arr[i] << " ";
  }

  cout << endl;

  delete[] arr;
  delete[] select_arr;
  return 0;
}

//------------------------------------------------------------------------------
