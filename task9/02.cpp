// Артамонов кирилл, Б01-005

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct student {
    std::string name;
    std::string id_number_string;
};

template<typename T>
bool operator== (student &st1, student &st2){
	if (st1.id_number_string == st2.id_number_string)
		return true;
	return false;
}

int main() {
    student a = {"Andy", "1234 123123"};
    student b = {"Andrew", "1234 123123"};
    student c = {"Andy", "1234123123"};
    cout << boolalpha << "Check result is: " << check_them(a, b, c) << endl; // to compile add check_them() definition
    return 0;
}
