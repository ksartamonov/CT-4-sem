// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Вывести сначала отсортированные по возрастанию неотрицательные, потом отсортированные по возрастанию модуля отрицательные.

#include <iostream>

using namespace std;

void arr_sort(int* array, int n)
{
  for (int i = 0; i < n - 1 ; ++i)
  {
    int min_idx = i; // min_idx - индекс наименьшего значения в этой итерации
    // начнем, что наименьший элемент - нулевой

    //ищем элемент меньше нашего минимума в остальной части массива
    for (int j = i + 1; j < n; ++j)
    {
      if (abs(array[j]) < abs(array[min_idx]))
        min_idx = j;
    }

    // в min_idx теперь наименьший элемент.
    // Меняем местами  начальное наименьшее число с тем, которое мы обнаружили
    swap(array[min_idx], array[i]);

  }
}

int main()
{
  int n; // количество чисел
  cin >> n;

  int* arr = new int[n];
  unsigned int pos_q = 0; // количество положительных элементов

  for (int i = 0 ; i < n ; i++)
  {
    cin >> arr[i]; // ввод массива
    if (arr[i] >= 0)
      pos_q++;
  }

  int* pos_arr = new int[pos_q];
  int* neg_arr = new int[n - pos_q];

  int i1 = 0, i2 = 0;

  for (int i = 0; i < n; ++i)
  {
		if (arr[i] < 0)
      neg_arr[i1++] = arr[i];
		else
			pos_arr[i2++] = arr[i];
	}

  arr_sort(pos_arr, pos_q);
  arr_sort(neg_arr, n - pos_q);

  for (int i = 0; i < pos_q; i++)
    cout << pos_arr[i] << " "; // вывод массива положительных

  for (int i = 0 ; i < n - pos_q ; i++)
    cout << neg_arr[i] << " "; // вывод массива отрицательных

  cout << endl;

  delete[] arr;
  delete[] pos_arr;
  delete[] neg_arr;

  return 0;
}
