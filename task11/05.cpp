#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(int a, int k) {
    return a > k ? 1 : 0;
}

int main(){
    int n = 0;
    cin >> n;

    vector<int> v;
    int x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        v.push_back(x);
    }

    int k = 0;
    cin >> k;

    auto newEnd = std::remove_if(v.begin(), v.end(), [&k](int num) {
        return num > k;
    });

    v.erase( newEnd, v.end());

    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
