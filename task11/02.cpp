// Артамонов Кирилл, Б01-005

#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> mst1, mst2;

    int n = 0;
    cin >> n;

    int x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        mst1.insert(x);
    }

    for (int i = 0; i < n; i ++) {
        cin >> x;
        mst2.insert(x);
    }

    if (mst1 == mst2)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
