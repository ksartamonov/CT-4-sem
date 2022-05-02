#include <iostream>
#include <map>
#include <vector>
#include <limits>
#include <set>

using namespace std;

class TelemetryController
{
private:

    map<string, vector<long>  > _devices;
public:
    TelemetryController() = default;
    ~TelemetryController() = default;
    // Получить и обработать событие. Параметрами передаются:
    // - device - идентификатор устройства, с которого пришло значение;
    // - value - собственно значение некоторой величины, переданное устройством.
    void handleEvent(const string& device, long value) {
        if (_devices[device].size() == 0) {
            _devices[device].resize(3);
            _devices[device][1] = LONG_MAX; // храним минимум
            _devices[device][2] = LONG_MIN; // храним максимум
        }

        if (value < _devices[device][1])
            _devices[device][1] = value;
        if (value > _devices[device][2])
            _devices[device][2] = value;
        _devices[device][0]++;
    }

    // По идентификатору устройства возвращает,
    // сколько всего значений от него пришло за всё время
    unsigned int getEventsCount(const string& device) const {
        return _devices.at(device)[0];
    }

    // По идентификатору устройства возвращает
    // минимальное значение за всё время, пришедшее от данного устройства
    long getMinValue(const string& device) const {
        return _devices.at(device)[1];
    }

    // По идентификатору устройства возвращает
    // максимальное значение за всё время, пришедшее от данного устройства
    long getMaxValue(const string& device) const {
        return _devices.at(device)[2];
    }
};

int main() {
    TelemetryController tc;
    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", -42);
    tc.handleEvent("d2", 100);
    cout << "Events count for d1: " << tc.getEventsCount("d1") << endl; cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
    cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;
}
