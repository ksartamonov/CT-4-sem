#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template<class T>
class Vector2D
{
private:
    T _X;
    T _Y;
public:
    // Конструкторы
    Vector2D() {};
    Vector2D(T x, T y): _X(x), _Y(y) {};
    // Деструктор
    ~Vector2D() {};
    // Получение координат
    T getX() const {
        return _X;
    }
    T getY() const {
        return _Y;
    }

    // Задание координат
    void setX(T x) {
        _X = x;
    }
    void setY(T y) {
        _Y = y;
    }
// Перегруженные операторы
    bool operator== (const Vector2D& v2) const {
        if (v2._X == _X && v2._Y == _Y)
            return true;
        return false;
    }
    bool operator!= (const Vector2D& v2) const {
        return !(v2 == *this);
    }

    Vector2D operator+ (const Vector2D& v2) const {
        return Vector2D(_X + v2._X, _Y + v2._Y);
    }

    Vector2D operator- (const Vector2D& v2) const {
        return Vector2D(_X - v2._X, _Y - v2._Y);
    }

    Vector2D operator* (const int a) const {
        return Vector2D(a * _X, a * _Y);
    }
};

template <class T>
Vector2D<T> operator*(int a, const Vector2D<T>& v) {
    return Vector2D<T>(a*v.getX() , a*v.getX());
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Vector2D<T>& v) {
    return out << "(" << v.getX()<< "; " << v.getY() << ")";
}

template <class T>
std::istream& operator>>(std::istream &in, Vector2D<T> &v) {
    T x, y;
    in >> x >> y;
    v.setX(x);
    v.setY(y);
    return in;
}

int main() {
    Vector2D<int> v1;
    cin >> v1;
    cout << "Read vector: " << v1 << endl;
    cout << "Vector multiplied by 42: " << v1 * 42 << endl;

    Vector2D<double> v2;
    cin >> v2;
    cout << "Read vector: " << v2 << endl;
    cout << "Vector multiplied by 42: " << v2 * 42 << endl;

    return 0;
}
