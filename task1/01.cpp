// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Вывод массива в обратном порядке
#include <iostream>

using namespace std;

int main()
{
  int n; // количество чисел
  cin >> n;

  int* arr = new int[n];

  for (int i = 0 ; i < n ; i++)
  {
    cin >> arr[i]; // ввод массива
  }

  for (int j = 1; j <= n;  j ++)
  {
    cout << arr[n-j] << " "; // Вывод преобразованного массива
  }
  cout << endl;

  delete[] arr;

  return 0;
}
