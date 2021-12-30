#include <iostream>
#include <vector>
using namespace std;
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
typedef long long ll;

// 1D
ll ruiseki_1D(vector<ll>& list, int left, int right) {
  vector<ll> slist(list.size() + 1, 0);
  for (size_t i = 1; i < list.size() + 1; i++) {
    slist[i] += slist[i - 1];
    slist[i] += list[i - 1];
  }

  // get [left, right)
  return slist[right] - slist[left];
}

ll ruiseki_2D(vector<vector<ll>>& list, int top, int left, int bottom,
              int right) {
  vector<vector<ll>> slist(list.size() + 1, vector<ll>(list[0].size() + 1, 0));

  for (size_t i = 1; i < list.size() + 1; i++) {
    for (size_t j = 1; j < list[0].size() + 1; j++) {
      slist[i][j] += slist[i][j - 1];
      slist[i][j] += slist[i - 1][j];
      slist[i][j] -= slist[i - 1][j - 1];
      slist[i][j] += list[i - 1][j - 1];
    }
  }

  // get [(top, left) (bottom, right))
  return slist[bottom][right] - slist[bottom][left] - slist[top][right] +
         slist[top][left];
}

int main() {
  // 1D
  vector<ll> list1 = {1, 2, 3, 4};
  cout << "[ ";
  REP(i, list1.size()) cout << list1[i] << " ";
  cout << " ]" << endl;

  cout << "[1, 3) " << ruiseki_1D(list1, 1, 3) << endl;
  cout << "[2, 4) " << ruiseki_1D(list1, 2, 4) << endl << endl;

  // 2D
  vector<vector<ll>> list2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

  cout << "[" << endl;
  REP(i, list2.size()) {
    REP(j, list2[0].size()) cout << list2[i][j] << " ";
    cout << endl;
  }
  cout << "]" << endl;

  cout << "[(1, 2) (4, 3)) " << ruiseki_2D(list2, 1, 2, 4, 3) << endl;
}