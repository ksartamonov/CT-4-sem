// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

// Написать функцию, которая анализирует массив структур, содержащий данные о персонажах 
// компьютерной игры, и находит тех, здоровье которых строго ниже определенного предела.

#include <iostream>

using namespace std;

struct Protoss {
unsigned long long int id;
unsigned int health, shield, position[2]; char name[100];
};

//------------------------------------------------------------------------------

unsigned int count_wounded(Protoss* army, unsigned int n, unsigned int threshold)
{
  unsigned int characters_amount = 0;

  for (int i = 0; i < n; i ++)
  {
    if (army[i].health < threshold)
      characters_amount++;
  }

  return characters_amount;
}

//------------------------------------------------------------------------------

int main() {
	Protoss army[10];
	for (int i = 0; i < 10; i++)
  {
		army[i].id = i;
		cin >> army[i].health >> army[i].shield >> army[i].position[0] >> army[i].position[1] >> army[i].name;
	}
	cout << count_wounded(army, 10, 100);
	cout << endl;
	return 0;
}
