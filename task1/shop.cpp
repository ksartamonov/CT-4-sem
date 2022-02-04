// Артамонов Кирилл, Б01-003 (перевод из Б01-005)

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

struct candies_box {
  unsigned int price;
  unsigned int quantity;
};

//------------------------------------------------------------------------------

void arr_sort(candies_box* array, int n)
{
  for (int i = 0; i < n - 1 ; ++i)
  {
    int min_idx = i; // min_idx - индекс наименьшего значения в этой итерации
    // начнем, что наименьший элемент - нулевой

    //ищем элемент меньше нашего минимума в остальной части массива
    for (int j = i + 1; j < n; ++j)
    {
      if (array[j].price < array[min_idx].price)
        min_idx = j;
    }

    // в min_idx теперь наименьший элемент.
    // Меняем местами  начальное наименьшее число с тем, которое мы обнаружили
    swap(array[min_idx], array[i]);

  }
}

//------------------------------------------------------------------------------

int main()
{
  int n;
  cin >> n; // ввод количества коробок

  candies_box* boxes = new candies_box[n];

  for (int i = 0; i < n; i ++)
  {
    cin >> boxes[i].price >> boxes[i].quantity; // считываем в массив струтур
  }
  unsigned int s;
  cin >> s; // ввод количества имеющихся денег
  arr_sort(boxes, n);

  int boxes_amount = 0, candies_amount = 0;

  for (int i = 0; i < n; ++i)
  {
    if (s >= boxes[i].price)
    {
      boxes_amount++;
      candies_amount += boxes[i].quantity;
      s -= boxes[i].price; // уменьшаем количество оставшихся денег по мере покупки конфет
    }
    else
      break; // не осталось денег 
  }

  cout << boxes_amount << " " << candies_amount;
  cout << endl;

  delete[] boxes;

  return 0;
}
