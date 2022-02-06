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
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < ll(n); i++)

constexpr int logn = 20;
constexpr int maxn = 1 << logn;

ll hilbertorder(int x, int y) {
  ll d = 0;
  for (int s = 1 << logn - 1; s; s >>= 1) {
    bool rx = x & s, ry = y & s;
    d = d << 2 | rx * 3 ^ static_cast<int>(ry);
    if (ry) continue;
    if (rx) {
      x = maxn - x;
      y = maxn - y;
    }
    swap(x, y);
  }
  return d;
}

vector<int> mos(vector<pair<int, int>>& queries, auto add, auto del,
                auto func) {  // [{l, r}, ...]
  vector<ll> ord(queries.size());
  vector<int> idx(queries.size());
  vector<int> ans(queries.size());
  int now_l = 0, now_r = 0;

  REP(i, queries.size()) {
    ord[i] = hilbertorder(queries[i].first, queries[i].second);
  }
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int a, int b) { return ord[a] < ord[b]; });
  REP(i, queries.size()) {
    while (now_l > queries[idx[i]].first) add(--now_l);
    while (now_r < queries[idx[i]].second) add(now_r++);
    while (now_l < queries[idx[i]].first) del(now_l++);
    while (now_r > queries[idx[i]].second) del(--now_r);
    ans[idx[i]] = func();
  }
  return ans;
}