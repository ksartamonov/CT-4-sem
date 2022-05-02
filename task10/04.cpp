#include <iostream>
#include <set>

using namespace std;

class Animal {
public:
    virtual string getType() const = 0;
    virtual ~Animal() {}
};

class ZooKeeper {
private:
    set <string> _animals;
public:
    // Создаём смотрителя зоопарка
    ZooKeeper();
    // Смотрителя попросили обработать очередного зверя.
    void handleAnimal(const Animal& a) {
        _animals.insert(a.getType()); // add animal to map
    }
// Возвращает, сколько зверей такого типа было обработано. // Если таких не было, возвращает 0.
    int getAnimalCount(const string& type) const {
        return _animals.count(type);
    }
};

int main() {
    ZooKeeper z;
    Animal *a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Lion();
    z.handleAnimal(*a);
    delete a;
    cout << z.getAnimalCount("monkey") << endl;
    cout << z.getAnimalCount("lion") << endl;
    cout << z.getAnimalCount("cat") << endl;
}
