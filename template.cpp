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
/*
#include <atcoder/all>
template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
ostream &operator<<(ostream &os, const atcoder::static_modint<m> &v) {
  os << v.val();
  return os;
}
*/

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

class dstream : private std::streambuf, public ostream {
 public:
  dstream() : std::ostream(this) {}
  dstream &operator<<(__attribute__((unused))
                      ostream &(*endl)(std::ostream &out)) {
#ifdef ATCODERDEBUG
    cout << endl;
#endif
    return *this;
  }
};

dstream dout;

template <typename T>
dstream &operator<<(dstream &os, const T &v) {
#ifdef ATCODERDEBUG
  cout << "\033[1;31m" << v << "\033[0m";
#endif
  return os;
}

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

template <class tTuple, std::size_t... indices>
void _print_tuple(ostream &os, tTuple const &iTuple,
                  std::index_sequence<indices...>) {
  using swallow = int[];
  os << "[ ";
  (void)swallow{(os << std::get<indices>(iTuple) << " , ", 0)...};
  os << " ]" << endl;
}

template <class... ARGS>
ostream &operator<<(ostream &os, const tuple<ARGS...> &v) {
  constexpr size_t N = tuple_size<tuple<ARGS...>>::value;
  _print_tuple(os, v, std::make_index_sequence<N>{});
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> v) {
  os << "[";
  while (!v.empty()) {
    os << v.top();
    v.pop();
    if (!v.empty()) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> v) {
  os << "[";
  while (!v.empty()) {
    os << v.front();
    v.pop();
    if (!v.empty()) {
      os << ", ";
    }
  }
  os << "]";
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

ll log10ll(ll n) {
  ll res = 0;
  while (n >= 10) {
    n /= 10LL;
    res++;
  }
  return res;
}

ll powll(ll a, ll b) {
  ll res = 1LL;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // cout << std::fixed << std::setprecision(15) << sqrt(ans) << endl;
}