// Артамонов Кирилл

#include <iostream>

using namespace std;

const double R = 8.31;

class GasHolder
{
public:
    // Создать газгольдер заданного объёма.
    // Температура созданного термостата равна 273 К.
    GasHolder(float v)
    {
      _V = v;
      _T = 273;
    }
    // Уничтожить газгольдер.
    ~GasHolder()
    {
      delete this;
    }
    // Впрыск порции газа массой m и молярной массой M.
    // Считать, что газ принимает текущую температуру газгольдера за пренебрежимо малое время.
    void inject(float m, float M)
    {
      _M = M;
      _m += m;
      _p += ((m / M) * R * _T) / _V;
    }
    // Подогреть газгольдер на dT градусов.
    // Считать, что нагрев возможен до любых значений температуры.
    void heat(float dT)
    {
      _T += dT;
      _p = ((_m / _M) * R * _T) / _V;
    }
    // Охладить газгольдер на dT градусов.
    // При попытке охладить ниже 0 К температура становится ровно 0 К.
    void cool(float dT)
    {
      if (_T < abs(dT))
        _T = 0;
      else
        _T -= dT;
      _p = ((_m / _M) * R * _T) / _V;
    }
    // Получить текущее давление в газгольдере.
    // Считать, что для газа верно уравнение состояния PV = (m/M)RT.
    // Значение постоянной R принять 8.31 Дж/(моль*К).
    float getPressure()
    {
      return _p;
    }
private:
    double _p;
    double _V;
    double _m;
    double _M;
    double _T;
};

int main()
{
GasHolder h(1.0);
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.inject(29, 29);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.heat(273);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
    h.cool(373);
    cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
}
