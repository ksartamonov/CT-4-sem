#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Brain {
protected:
// Здесь хранится что-то очень ценное.
// Наверное, набор волшебных чисел для нейронной сети, управляющей гоблином.
    vector<double> data;
// А здесь просто фраза, которой гоблин откликается по умолчанию
    string phrase;
public:
// Конструктор мозга
    Brain() {
    // Мозг занимает в памяти много места, да
        try {
            data.resize(1000000);
        }
        catch(std::bad_alloc) {
            cout << "[err] cannot allocate memory!" << endl;
        }
    // Установим эталонную фразу
        phrase = "Booyahg Booyahg Booyahg";
    }
    // Мозг умеет подсказать гоблину, какую фразу выдать
    string speak() {
        return phrase;
    }
};

class Goblin {
private:
    Brain* _brain; // указатель на мозг армии гоблинов
public:
// Подходящие конструкторы и деструкторы
    explicit Goblin(Brain* brain) {
        _brain = brain;
    }

    virtual ~Goblin() = default;
    // Просто вернуть фразу, которую гоблину подсказывает мозг
    // (Метод используется для проверки, что голова гоблина содержит правильный мозг)
    string speak() {
        return _brain->speak();
    }
};

// Получает size - требуемый размер армии. Возвращает вектор гоблинов требуемого размера.
// На всю армию создаёт один мозг, к которому имеют доступ все гоблины армии.
// Мозг можно создать просто как Brain(), либо new Brain(), либо любым другим способом создания объекта.
vector<Goblin> create_goblin_army(unsigned int size) {
    auto* br = new Brain();
    vector <Goblin> army;

    for (int i = 0; i < size; i++) {
        Goblin gb = Goblin(br);
        army.push_back(gb);
    }
    return army;
}

int main() {
    unsigned int size1 = 1;
    unsigned int size2 = 10;

    vector<Goblin> army1 = create_goblin_army(size1);
    vector<Goblin> army2 = create_goblin_army(size2);

    for (unsigned int i = 0; i < size1; i++) {
        cout << army1[i].speak() << endl;
    }
    for (unsigned int i = 0; i < size2; i++) {
        cout << army2[i].speak() << endl;
    }

    return 0;
}
