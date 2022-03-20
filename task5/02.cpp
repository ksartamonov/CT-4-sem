// Артамонов Кирилл

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Storage {
public:
// Конструктор хранилища размерности n
   Storage(unsigned int n) {
      _arr = new int[n];
      _size = n;
   }
// Добавьте нужный деструктор
   ~Storage() {
      delete[] _arr;
   }
// Получение размерности хранилища
   unsigned getSize() {
      return _size;
   }

// Получение значения i-го элемента из хранилища, // i находится в диапазоне от 0 до n-1,
// случаи некорректных i можно не обрабатывать.
   int getValue(unsigned int i) {
      return _arr[i];
   }

// Задание значения i-го элемента из хранилища равным value, // i находится в диапазоне от 0 до n-1,
// случаи некорректных i можно не обрабатывать.
   void setValue(unsigned int i, int value) {
      _arr[i] = value;
   }
private:
   int* _arr;
   int _size;
};

// Класс TestStorage, наследуется от вашей реализации Storage
class TestStorage : public Storage {
protected:
// Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
   int* more_data;
public:
// В конструкторе память выделяется,
   TestStorage(unsigned int n) : Storage(n) {
      more_data = new int[n];
   }
// ... а в деструкторе освобождается - всё честно.
   ~TestStorage() {
      delete[] more_data;
   }
};

int main() {
   Storage *ts = new TestStorage(42);
   delete ts;
   return 0;
}
