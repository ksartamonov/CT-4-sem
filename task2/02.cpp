// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//------------------------------------------------------------------------------

void worry_count(vector <bool> &v)
{
  size_t worried = 0;
  for (auto i : v)
  {
    if (v[i] == true) // беспокоящихся людей помечаем true, а спокойных - false
      worried++;
  }
  cout << worried << endl;
}

void worry(vector <bool> &v, int argument)
{
  v[argument] = true; // помечаем i-го беспокоящимся
}

void quiet(vector <bool> &v, int argument)
{
  v[argument] = false; // помечаем i-го спокойным
}

void come(vector <bool> &v, int argument)
{
    v.resize(v.size() + (argument)); // при увеличении размера вектор дозаполнится false, а при уменьшении удалит последних
}


//------------------------------------------------------------------------------

int main()
{
  int Q;  // количество инструкций
  cin >> Q;

  vector <bool> v;

  string command; // название команды
  int argument; // аргумент для некоторых команд

  for (int i = 0; i < Q; i++)
  {
    cin >> command;

    if (command == "WORRY_COUNT")
      worry_count(v);

    else if  (command == "WORRY")
    {
      cin >> argument;
      worry(v, argument);
    }

    else if (command == "QUIET")
    {
      cin >> argument;
      quiet(v, argument);
    }

    else if (command == "COME")
    {
      cin >> argument;
      come(v, argument);
    }

  }

  return 0;
}
