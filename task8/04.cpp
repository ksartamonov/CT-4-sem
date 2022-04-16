// Артамонов Кирилл

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int corrections_amount(const string& b, const string& a) {
    if (b.size() > a.size()) {
        return corrections_amount(a, b);
    }

    int min_size = b.size(), max_size = a.size();
    std::vector<int> levenstein_distance(min_size + 1);

    for (int i = 0; i <= min_size; ++i) {
        levenstein_distance[i] = i;
    }

    for (int j = 1; j <= max_size; ++j) {
        int prev_diag = levenstein_distance[0], prev_diag_save;
        ++levenstein_distance[0];

        for (int i = 1; i <= min_size; ++i) {
            prev_diag_save = levenstein_distance[i];
            if (b[i - 1] == a[j - 1]) {
                levenstein_distance[i] = prev_diag;
            } else {
                levenstein_distance[i] = min(min(levenstein_distance[i - 1], levenstein_distance[i]), prev_diag) + 1;
            }
            prev_diag = prev_diag_save;
        }
    }

    return levenstein_distance[min_size];
}

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << corrections_amount(a, b) << endl;
    return 0;

}
