// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Поворот картинки на 90 градусов против часовой стрелки

#include <iostream>
// #include <cstdio>

using namespace std;
void rotated_picture_print(char** pic, int& n, int& m) // вывод уже повернутой картинки
{
  for (int j = m - 1; j >= 0; --j) // идем по столбцам назад
  {
    for (int i = 0; i < n; ++i) // по строкам
      cout << pic[i][j] << " ";
    cout << endl;
  }
}



int main()
{
	int n,m;
	cin >> n >> m; // ввод числа строк, числа столбцов
	char** picture = new char*[n]; // интерпретируем картинку как матрицу
  char c;

	for (int i = 0; i < n; ++i) // считываем рисунок
  {
		picture[i] = new char[m];
		int read_q = 0; // счетчик  считанных символов( в строке)
		while (read_q != m)
    {
			cin.get(c);
			if (c != '\n' && c != '\0')
      {
				picture[i][read_q++] = c;
			}
		}
	}

	rotated_picture_print(picture, n, m);
	cout << endl;

  delete[] picture;

  return 0;
}
