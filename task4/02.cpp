// Артамонов Кирилл

#include <iostream>

using namespace std;

class Item {
public:
    Item(string title, int weight, int level, bool magical) : _title(title), _weight(weight), _level(level), _magical(magical) {}

    ~Item() = default;

    int getWeight() {
        return _weight;
    }
    int getLevel() {
        return _level;
    }
    bool isMagical() {
        return _magical;
    }
private:
    string _title;
    int _weight;
    int _level;
    bool _magical;
};

class Player {
protected:
    int strength;
    int level;
public:
    Player() : strength(0), level(0) {}
    virtual ~Player() {}
    void setStrength(int strength) {
        this->strength = strength;
    }
    void setLevel(int level) {
            this->level = level;
    }
    int getStrength() {
        return this->strength;
    }
    int getLevel() {
        return this->level;
    }
    virtual bool canUse(Item* item) = 0;
};

class Knight : public Player {
    bool canUse(Item* item) override {
        return (!item->isMagical()) && (strength >= item->getWeight()) && (level >= item->getLevel());
    }
};

class Wizard : public Player {
    bool canUse(Item* item) override {
        return (strength >= item->getWeight()) && (level >= item->getLevel());
    }
};

int main()
{
  Item* items[3];
   items[0] = new Item("Small sword", 1, 1, false);
   items[1] = new Item("Big sword", 5, 3, false);
   items[2] = new Item("Ward", 1, 3, true);
   Player* players[2];
   players[0] = new Wizard();
   players[0]->setStrength(3);
   players[0]->setLevel(5);
   players[1] = new Knight();
   players[1]->setStrength(6);
   players[1]->setLevel(5);
   for(int i = 0; i < 2; i++) {
       for(int j = 0; j < 3; j++) {
cout << "Can use: " << players[i]->canUse(items[j]) << endl; }
}
}
