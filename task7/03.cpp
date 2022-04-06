#include <iostream>
#include <vector>

using namespace std;

class VectorN
{
private:
    std::vector <int> _components;
    uint _size;
public:
    // Конструктор вектора размерности n
    VectorN(unsigned int n) {
        _components.resize(n);
        _size = n;
    };
    // Деструктор
    ~VectorN() {};
    // Получение размерности вектора
    unsigned getSize() const {
        return _size;
    }
// Получение значения i-ой координаты вектора, // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const {
        return _components[i];
    }
// Задание значения i-ой координаты вектора равным value, // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value) {
        _components[i] = value;
    }
    /*
     * Далее реализуйте перегруженные операторы
     */
    // Оператор == проверяет два вектора на равенство
    // равны они, если строго равны всех их координаты
    bool operator== (const VectorN& v2) const {
        for (int i = 0; i < _size; i++) {
            if (_components[i] != v2.getValue(i))
                return false;
        }
        return true;
    }

    // Оператор != проверяет два вектора на неравенство,
    // они не равны, если хотя бы одна координата отличается
    bool operator!= (const VectorN& v2) const {
        return !(*this == v2);
    }

    // Оператор + складывает два вектора покоординатно, // возвращает результат как новый экземпляр вектора
    VectorN operator+ (const VectorN& v2) const {
        VectorN v(_size);
        for (int i = 0; i < _size; i++) {
           v.setValue(i, getValue(i) + v2.getValue(i));
        }
        return v;
    }

    // Оператор * умножает вектор на скаляр типа int покоординатно,
    // возвращает результат как новый экземпляр вектора.
    VectorN operator* (const int a) const {
        VectorN v_res(_size);
        for (int i = 0; i < _size; i++) {
            v_res.setValue(i, _components[i] * a);
        }
        return v_res;
    }

    // Умножение должно работать при любом порядке операндов.
};

VectorN operator* (int a, const VectorN& v) {
    VectorN v_res(v.getSize());
    for (int i = 0; i < v.getSize(); i++) {
        v_res.setValue(i, v.getValue(i) * a);
    }
    return v_res;
}

int main() {

    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);
    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);
    cout << (a == b) << endl;
    cout << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;

    return 0;
}
