// Артамонов Кирилл

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    std::string _name;
    uint _score;

public:
    Student() {};
    // Задать имя студента
    void setName(string name) {
        _name = name;
    }
    // Указать количество баллов за контрольную
    void setScore(unsigned int score) {
        _score = score;
    }
    // Получить имя студента
    string getName() const {
        return _name;
    }
    // Получить количество баллов студента
    unsigned int getScore() const {
        return _score;
    }

    friend istream& operator>> (istream &in, Student &st);

    friend ostream& operator<< (ostream &out, const Student &st);
};

istream& operator>>(std::istream &in, Student &st) {
    // in >> st._name;
    getline(in, st._name);
    st.setScore(0);
    return in;
}

ostream& operator<<(std::ostream &out, const Student &st) {
    return  out << "'" << st.getName() << "': " << st.getScore();
}


int main() {
    Student s;
    cin >> s;
    s.setScore(10);
    cout << s << std::endl;
}
