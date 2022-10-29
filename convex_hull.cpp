#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using point = pair<long double, long double>;
using points = vector<point>;

long double cross(point o, point a, point b) {
  return (a.first - o.first) * (b.second - o.second) -
         (a.second - o.second) * (b.first - o.first);
}

points lower_hull(points p) {
  int n = p.size(), k = 0;
  sort(p.begin(), p.end());
  vector<point> res(n);
  for (int i = 0; i < n; i++) {
    while (k >= 2 and cross(res[k - 2], res[k - 1], p[i]) <= 0) k--;
    res[k++] = p[i];
  }
  res.resize(k);
  return res;
}

points upper_hull(points p) {
  int n = p.size(), k = 0;
  sort(p.begin(), p.end());
  vector<point> res(n);
  for (int i = 0; i < n; i++) {
    while (k >= 2 and cross(res[k - 2], res[k - 1], p[i]) >= 0) k--;
    res[k++] = p[i];
  }
  res.resize(k);
  return res;
}

int main() {
  points ps{{3, 1}, {2, 2}, {1, 0}, {0, -2}, {0, 0}, {0, 3}, {-1, 2}, {-2, 1}};

  auto lh = lower_hull(ps);
  auto uh = upper_hull(ps);

  for (auto p : lh) {
    cout << " { " << p.first << ", " << p.second << " } ";
  }
  cout << endl;

  for (auto p : uh) {
    cout << " { " << p.first << ", " << p.second << " } ";
  }
  cout << endl;
}