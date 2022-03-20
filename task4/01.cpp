// Артамонов Кирилл

#include <iostream>

using namespace std;

class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class Monkey : public Animal {
public:
    Monkey() : _isDangerous(false) {}
    ~Monkey() = default;
    bool isDangerous() override {
        return _isDangerous;
    }
    string getType() override {
        return "Monkey";
    }
private:
    bool _isDangerous;
};

class Lion : public Animal {
public:
    Lion() : _isDangerous(true) {}
    ~Lion() = default;
    string getType() override {
        return "Lion";
    }
    bool isDangerous() override {
        return _isDangerous;
    }
private:
    bool _isDangerous;
};

class ZooKeeper {
public:
  // Создаём смотрителя зоопарка
  ZooKeeper(int dangerous_amount = 0) : _dangerous_amount(dangerous_amount) {}
// Смотрителя попросили обработать очередного зверя.
// Если зверь был опасный, смотритель фиксирует у себя этот факт.
  void handleAnimal(Animal* a)
  {
      if (a->isDangerous())
        _dangerous_amount++;
  }

// Возвращает, сколько опасных зверей было обработано на данный момент.
  int getDangerousCount()
  {
    return _dangerous_amount;
  }

private:
  uint _dangerous_amount;
};

int main() {
    ZooKeeper z;
    Monkey* m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion* l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;
    return 0;
}
