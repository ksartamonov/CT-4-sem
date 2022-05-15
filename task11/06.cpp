#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> V;
  int x;
  for (int i = 0; i < n; i++) {
  	cin >> x;
  	V.push_back(x);
  }

  vector<int> V1(V), V2(V), V3();

  vector<int> :: iterator it = remove_if(V1.begin(), V1.end(), [](int k){return (k % 2) != 0;});
  V1.erase (it, V1.end());
  sort(V1.begin(), V1.end(), greater<int>());

  vector<int> :: iterator it1 = remove_if(V2.begin(), V2.end(), [](int k){return (k % 2) == 0;});
  V2.erase (it1, V2.end());
  sort(V2.begin(), V2.end());

  int j = 0, k = 0;
  for (int i = 0; i < n; i++){
    if (V[i] % 2 != 0){
      V[i] = V2[j];
      j++;
    }

    if (V[i] % 2 == 0){
      V[i] = V1[k];
      k++;
    }
  }

  copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;

  return 0;
}
