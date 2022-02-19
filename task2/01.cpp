// Артамонов Кирилл, Б01-003 (перевод из Б01-005)


#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector <int> v(n);
  int sum = 0;

  for (int i = 0; i < n; i ++)
  {
    cin >> v[i];
    sum += v[i];
  }

  int medium = sum / n ;

  int k = 0; // количество дней, удовлетворяющих условию
  for (int i = 0; i < n; i++)
  {
    if (v[i] > medium)
      k++;
  }

  cout << k << endl;

  for (int i = 0; i < n; i ++)
  {
    if (v[i] > medium)
      cout << i << " ";
  }

  cout << endl;
  return 0;
}
