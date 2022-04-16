// Артамонов Кирилл

#include <iostream>
#include <string>

using namespace std;

void find_str (string a, string b) // finds string b in string a
{
    int k = -1;
    for (int i = 0; i < b.size(); i++) {
        if ((b.substr(i, a.size()) == a) && i + a.size() <= b.size()) {
            cout << i << " ";
            k++;
        }
    }
    if (k == -1)
        cout << k;
    cout << endl;
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    find_str(a, b);
    return 0;

}
