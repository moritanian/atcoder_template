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
using ll = long long;

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

template <typename T>
dstream &operator<<(dstream &os, const T &v) {
#ifdef ATCODERDEBUG
  cout << "\033[1;31m" << v << "\033[0m";
#endif
  return os;
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

const ll B1 = 100000007LL;
const ll B2 = 1000000007LL;

const ll C1 = 998244353LL;
const ll C2 = 1000000009LL;

vector<ll> rolling_hash(string s) {
  ll h1 = 0;
  ll h2 = 0;

  vector<ll> H(s.size());
  for (int i = 0; i < s.size(); i++) {
    h1 *= B1;
    h1 += s[i];
    h1 %= B2;

    h2 *= C1;
    h2 += s[i];
    h2 %= C2;

    H[i] = (h1 << 32) + h2;
  }
  return H;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s1 = "abccdabccdx";
  string s2 = "abc";

  vector<ll> H1 = rolling_hash(s1);
  vector<ll> H2 = rolling_hash(s2);

  dout << H1 << endl;
  dout << H2 << endl;
  for (int i = 0; i < H1.size(); i++) {
    if (H1[i] == H2[2]) {
      cout << i << endl;
    }
  }
}