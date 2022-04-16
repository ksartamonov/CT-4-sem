// Артамонов Кирилл

#include <iostream>
#include <string>

using namespace std;

int A_func(string str) {
    int ans = 0;

    for (int k = 1; k < str.size() + 1; k++) {
        string s1, s2;

        for (int i = 0; i < k; i ++) {
            s1 += str[i];
            s2 += str[str.size() - i - 1 ];
        }

        if (s1 == s2)
            ans++;

        else
            break;
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);

    for (int i = 1; i < s.size() + 1; i++) {
        cout << A_func(s.substr(0, i)) << " ";
    }
    cout << endl;
    return 0;
}
