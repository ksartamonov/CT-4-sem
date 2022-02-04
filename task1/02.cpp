// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Вывод элементов, которые больше среднего арифметического
#include <iostream>

using namespace std;

int main()
{
  int n; // количество чисел
  cin >> n;

  int* arr = new int[n];

  int sum = 0; // Сумма элементов массива
  for (int i = 0 ; i < n ; i++)
  {
    cin >> arr[i]; // ввод массива
    sum += arr[i];
  }

  double mid = (double)(sum) / n; // подсчет среднего арифметического

  for (int i = 0; i < n; i ++)
  {
    if (arr[i] > mid) // проверяем условие
      cout << arr[i] << " ";
  }
  cout << endl;

  delete[] arr;

  return 0;
}
