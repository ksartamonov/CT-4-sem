// Артамонов Кирилл, Б01-005

#include <iostream>
#include <set>
#include <vector>
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

    vector<int>::iterator ins;
    vector<int> v(n);
    ins = set_intersection(mst1.begin(), mst1.end(), mst2.begin(), mst2.end(), v.begin());

    for (auto it = v.begin(); it != ins; ++it)
        std::cout << *it << " ";
    std::cout << endl;

    return 0;
}
