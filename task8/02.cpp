// Артамонов Кирилл

#include <iostream>
#include <string>

using namespace std;

string loop_left_offset(string& s) {
    char s0;
    s0 = s[0];
    for (int i = 0; i < s.size() - 1; i++) {
        s[i] = s[i+1];
    }
    s[s.size() - 1] = s0;
    return s;
}

int offset_len(string a, string b) {
    int ans = 0;
    int symb = 0;
    while (symb != a.size()) {
        if (a == b)
            return ans;

        if (loop_left_offset(a) != b)
            ans++;

        if (loop_left_offset(a) == b) {
            ans++;
            return ans;
        }

        symb++;
    }

    return -1;
}
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    cout << offset_len(a, b) << endl;
    return 0;

}
