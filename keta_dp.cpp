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

// #include <atcoder/all>
/*
cd $dir && g++ -std=c++17 -Wall -Wextra -O2 -DATCODERDEBUG
-I/home/moritanian/projects/atcoder/lib/ac-library $fileName && \
 echo 'compilation ok!'
&&  ./a.out
*/
using namespace std;
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define FOR(i, a, b) for (ll i = a; i <= ll(b); i++)
#define ALL(x) x.begin(), x.end()
#define dame(a)        \
  {                    \
    cout << a << endl; \
    return 0;          \
  }
typedef long long ll;

ll __per__(ll a, ll b) {
  if (a >= 0) return a % b;
  return (((-a - 1LL) / b) + 1LL) * b + a;
}

class dstream : public ostream {};

template <typename T>
dstream &operator<<(dstream &os, const T &v) {
#ifdef ATCODERDEBUG
  cout << "\033[1;31m" << v << "\033[0m";
#endif
  return os;
}

ostream &endd(std::ostream &out) {
#ifdef ATCODERDEBUG
  out << std::endl;
#endif
  return out;
}
dstream dout;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[ ";
  for (auto const &x : v) {
    os << x;
    if (&x != &v.back()) {
      os << " , ";
    }
  }
  os << " ]";
  return os;
}

ostream &operator<<(ostream &os, const vector<bool> &v) {
  os << "[ ";
  for (size_t i = 0; i < v.size(); i++) {
    os << v[i];
    if (i != v.size() - 1) {
      os << " : ";
    }
  }
  os << " ]";
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
  os << "[" << endl;
  for (auto const &x : v) {
    os << " ";
    os << x;
    os << endl;
  }
  os << "]";
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &v) {
  os << "{" << endl;
  for (auto const &x : v) {
    os << " ";
    os << x;
  }
  os << "}" << endl;
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const unordered_map<T, U> &v) {
  os << "{" << endl;
  for (auto const &x : v) {
    os << " ";
    os << x;
  }
  os << "}" << endl;
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const multimap<T, U> &v) {
  os << "{" << endl;
  for (auto const &x : v) {
    os << " ";
    os << x;
  }
  os << "}" << endl;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  for (auto const &x : v) {
    os << " ";
    os << x;
  }
  os << " }" << endl;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &v) {
  os << "{";
  for (auto const &x : v) {
    os << " ";
    os << x;
  }
  os << " }" << endl;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  for (auto const &x : v) {
    os << " ";
    os << x;
  }
  os << " }" << endl;
  return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &v) {
  os << "< " << v.first << " : " << v.second << " >";
  return os;
}

template <typename T, typename U, typename Comp = less<>>
bool chmax(T &xmax, const U &x, Comp comp = {}) {
  if (comp(xmax, x)) {
    xmax = x;
    return true;
  }
  return false;
}

template <typename T, typename U, typename Comp = less<>>
bool chmin(T &xmin, const U &x, Comp comp = {}) {
  if (comp(x, xmin)) {
    xmin = x;
    return true;
  }
  return false;
}

/**
 * Calculate kind of numbers at least one of digit is 3 and <= N.
 *
 * https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab
 */
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int D = 2;

  string N;
  cin >> N;
  vector<ll> n;

  for (auto v : N) {
    n.emplace_back(v - '0');
  }

  ll K = n.size();

  vector<vector<vector<ll>>> dp(K + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
  dp[0][0][0] = 1;

  REP(k, K) {          // digit (1: first left digit)
    REP(smaller, 2) {  // 0: same with N, 1: less than N
      REP(found, 2) {  // found at least one '3' digit
        REP(x, (smaller ? 10 : n[k] + 1)) {
          dp[k + 1][smaller || x < n[k]][found || x == D] +=
              dp[k][smaller][found];
        }
      }
    }
  }

  cout << (dp[K][0][1] + dp[K][1][1]) << endl;
  // cout << std::fixed << std::setprecision(15) << sqrt(ans) << endl;
}