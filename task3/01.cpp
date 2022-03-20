// Артамонов Кирилл

#include <iostream>

using namespace std;

class Train
{
public:
    // Создать паровоз массой m,
    // стоящий в начале координат
    Train(double m)
    {
      _weight = m;
      _v = 0;
      _x = 0;
    }
    // Ехать с текущей скоростью в течение времени dt
    void move(double dt)
    {
      _x += _v * dt;
    }
    // Изменить полный импульс паровоза (p = mv) на dp
    // Изменение может менять знак скорости
    void accelerate(double dp)
    {
      double dv = dp / _weight;
      _v += dv;
    }
    // Получить текущую координату паровоза
    double getX()
    {
      return _x;
    }
private:
  double _weight;
  double _v;
  double _x;
};


int main()
{
  Train t(10);
  t.accelerate(1); // Скорость стала 0.1
  t.move(1);
  cout << "Current X: " << t.getX() << endl;
  t.move(1);
  cout << "Current X: " << t.getX() << endl;
  t.accelerate(-2); // Скорость стала -0.1
  t.move(3);
  cout << "Current X: " << t.getX() << endl;
}
