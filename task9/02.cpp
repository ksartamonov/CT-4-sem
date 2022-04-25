#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct student {
    std::string name;
    std::string id_number_string;
};

template<typename T>
bool check_them(T& x, T& y, T& z) {
    if (x.id_number_string == y.id_number_string && y.id_number_string == z.id_number_string)
        return true;
    return false;
}

int main() {
    student a = {"Andy", "1234 123123"};
    student b = {"Andrew", "1234 123123"};
    student c = {"Andy", "1234123123"};
    cout << boolalpha << "Check result is: " << check_them(a, b, c) << endl;
    return 0;
}
