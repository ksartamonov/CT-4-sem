// Артамонов Кирилл
#include <iostream>
#include <vector>

using namespace std;

class Task
{
protected:
    int cpuNum;
    int size;
public:
    Task(int cpuNum, int size) {
        this->cpuNum = cpuNum;
        this->size = size;
    }
    // На каком ядре процессора выполняется задача
    int getCPU() const {
        return cpuNum;
    }
// Оценка сложности задачи (в попугаях)
    int getSize() const {
        return size;
    }
};


class Analyzer
{
private:
    vector <int> _CPU_loads;
    int _numCores;
public:
// Создать анализатор для системы с numCores ядер
    Analyzer(int numCores)  {
    _CPU_loads.resize(numCores);
    _numCores = numCores;
};
    virtual ~Analyzer() {};
// Проанализировать текущие задачи
    void analyze(const vector<Task>& tasks) {
        for (int i = 0; i < tasks.size(); i ++) {
            _CPU_loads[tasks[i].getCPU()] += tasks[i].getSize();
        }
    }
    // Сообщить общую нагрузку на заданное ядро
    int getLoadForCPU(int cpuNum) {
        return _CPU_loads[cpuNum];
    }
};

int main() {
    int numberOfCores = 4;
    vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} }; Analyzer a(numberOfCores);
    a.analyze(data);
    for(int i = 0; i < numberOfCores; i++)
        cout << a.getLoadForCPU(i) << endl;

    return 0;
}
