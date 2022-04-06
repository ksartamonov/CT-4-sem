#include <iostream>

using namespace std;

class Vector2D
{
private:
    int _x;
    int _y;
public:
    // Конструкторы
    Vector2D() {};
    Vector2D(int x, int y): _x(x), _y(y) {};
    // Деструктор
    ~Vector2D() {};
    // Получение координат
    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }

    // Задание координат
    void setX(int x) {
        _x = x;
    }

    void setY(int y) {
        _y = y;
    }

// Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const {
        return (_x == v2._x && _y == v2._y);
    }

// Ещё один перегруженный оператор - неравенство векторов
// Да, это отдельный оператор! Хинт - настоящие джедаи смогут для != использовать уже написанное ==
bool operator!= (const Vector2D& v2) const {
    return !(*this == v2);
}

    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator+ (const Vector2D& v2) const {
        return Vector2D(_x + v2._x, _y + v2._y);
    }

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector2D operator- (const Vector2D& v2) const {
        return Vector2D(_x - v2._x, _y - v2._y);
    }
    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector2D operator* (const int a) const {
        return Vector2D(a * _x, a * _y);
    }
};
// Оператор умножения скаляра на вектор, исходный вектор не меняется, возвращается новый вектор
// Неожиданно, правда? Умножение скаляра на вектор - это отдельный оператор, причём описанный *вне* класса.
Vector2D operator* (int a, const Vector2D& v) {
    return Vector2D(a*v.getX() , a*v.getX());
}

// Вывод вектора, ожидается строго в формате (1; 1)
std::ostream& operator<<(std::ostream& out, const Vector2D& v) {
    return out << "(" << v.getX()<< "; " << v.getY() << ")";
}
// Чтение вектора, читает просто две координаты без хитростей
std::istream& operator>>(std::istream &in, Vector2D &v) {
    int x, y;
    in >> x >> y;
    v.setX(x);
    v.setY(y);
    return in;
}

int main() {
    Vector2D v1;
    cin >> v1;
    cout << v1 << endl;
    Vector2D v2;
    cin >> v2;
    cout << v2 << endl;
    cout << boolalpha << (v1 == v2) << endl;
    cout << boolalpha << (v1 != v2) << endl;
    Vector2D v3 = v1 - v2;
    cout << v3 << endl;
    cout << v3 * 42 << endl;
    cout << 42 * v3 << endl;
}
