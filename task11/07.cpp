#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Storage
{
private:
	vector<int> v;
public:
	// Конструктор хранилища размерности n
	Storage(unsigned int n){
		for (int i = 0; i < n; i++) {
			v.push_back(0);
		}

	}

	// Добавьте деструктор, если нужно
	// Получение размерности хранилища
	unsigned int getSize() const{
		return v.size();
	}

	// Получение значения i-го элемента из хранилища
	// Если индекс некорректен, нужно выбросить IncorrectIndexException
	int getValue(unsigned int i) const{
		if (i < 0 || i >= v.size()){
			 throw std::invalid_argument("IncorrectIndexException");
		}
		return v[i];
	}

	// Задание значения i-го элемента из хранилища равным value
	// Если индекс некорректен, нужно выбросить IncorrectIndexException
	void setValue(unsigned int i, int value){
		if (i < 0 || i >= v.size()){
			 throw std::invalid_argument("IncorrectIndexException");
		}
		v[i] = value;
	}
};


int main() {
	unsigned int index;
	std::cin >> index;
	Storage s(42);
	s.setValue(index, 0);
	std::cout << s.getValue(index) << std::endl;
	return 0;
}
