// Артамонов Кирилл

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person
{
private:
    string _surname;
    string _name;
    string _middleName;
public:
    // Создать человека с ФИО
    Person(string surname, string name, string middleName): _surname(surname),
                                                            _name(name),
                                                            _middleName(middleName) {}
    Person() = default;
    ~Person() = default;

    string getSurname() const{
        return _surname;
    }

    string getName() const{
        return _name;
    }

    string getMiddleName() const{
        return _middleName;
    }

    void setSurname(string surname){
        _surname = surname;
    }

    void setName(string name){
        _name = name;
    }

    void setSMiddleName(string middleName){
        _middleName = middleName;
    }

    bool operator<(const Person& p2) {
        if (p2.getSurname() > _surname) {
            return true;
        }
        else if (p2.getSurname() == _surname) {
            if (p2.getName() > _name) {
                return true;
            }
            else if (p2.getName() == _name) {
                if (p2.getMiddleName() > _middleName)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
};

std::ostream& operator<<(std::ostream& out, const Person& p) {
    return out << p.getSurname()<< " " << p.getName() << " " << p.getMiddleName();
}
// Чтение вектора, читает просто две координаты без хитростей
std::istream& operator>>(std::istream &in, Person& p) {
    string name, surname, middleName;
    in >>  surname >> name >> middleName;
    p.setSurname(surname);
    p.setName(name);
    p.setSMiddleName(middleName);
    return in;
}

int main() {
    cout << "Testing I/O" << endl;
    Person p;
    cin >> p;
    cout << p << endl;

    cout << "Testing sorting" << endl;
    vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));

    sort(people.begin(), people.end());
    for(vector<Person>::const_iterator it = people.begin(); it < people.end(); it++) {
        cout << *it << endl;
    }
}
