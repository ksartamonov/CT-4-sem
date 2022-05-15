#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    vector<int> mst1, mst2;

    int n = 0;
    cin >> n;

    int x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        mst1.push_back(x);
    }

    for (int i = 0; i < n; i ++) {
        cin >> x;
        mst2.push_back(x);
    }

    sort(mst2.begin(), mst2.end());
    sort(mst1.begin(), mst1.end());

    vector<int> v;

    set_intersection(mst1.begin(),mst1.end(),mst2.begin(),mst2.end(), back_inserter(v));

    for(auto it : v)
        cout << it << ' ';

    cout << endl;
    return 0;
}
