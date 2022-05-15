// Артамонов Кирилл, Б01-005

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    int x;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++)
        cout << v[n - 1 - i] << " ";

    cout << endl;

    return 0;
}
