// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

vector<string> next(vector<string>& d1, const vector<int>& m, int& i, vector<string>& d2)
{
	d2 = d1; // новый месяц
	d1.resize(m[i]); // изменяем до размера нового месяца
	int s1 = d1.size();
	int s2 = d2.size();
	int delta = 0;

	if (s1 < s2) // если в старом месяце меньше
	{
		delta = s2 - s1;
		for (int j = d2.size() - delta; j < d2.size(); j++)
		{
			d2[d2.size() - delta - 1] += d2[j]; // добавляем дело в новый  месяц
		}

	}
	d2.resize(m[i]);
	i++; // итератор месяца

	if (i == 12)
		i = 0;

	return d2; // возвращаем новый вектор
}


//------------------------------------------------------------------------------

void add(vector<string>& days, int day, string job_name)
{
	days[day-1] += job_name + " ";
}

//------------------------------------------------------------------------------

void dump(int day, const vector<string>& days) // вывод задач в определенный день
{
	int count = 0;
	for (int j = 0; j < days[day - 1].size(); j++)
	{
		if (days[day - 1][j] != ' ' && (days[day - 1][j + 1] == ' ' || days[day - 1][j + 1] == '\0'))
			count++; // номер дела
}

cout << count << " " << days[day-1] << endl;
}

//------------------------------------------------------------------------------

int main()
{
  vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // количество дней в месяцах

  unsigned int Q; // количество операций

  cin >> Q;

	vector<string> days(months[0]);
	vector<string> days_new;

  string command;
  unsigned int day;
  string job_name;

  for ( int i = 0; i < Q; i++)
  {
    cin >> command;

    if (command == "ADD")
    {
      cin >> day;
      cin >> job_name;
      add(days, day, job_name);
    }

    else if (command == "NEXT")
    {
      days_new = next(days, months, i, days_new);
			days = days_new;
    }

		else if (command == "DUMP")
		{
			cin >> day;
			dump(day, days);
		}
  }

	return 0;


}
