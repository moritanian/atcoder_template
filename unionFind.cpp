#include <vector>

using namespace std;
typedef long long ll;

struct UF {
  vector<ll> data;
  UF(ll size) : data(size, -1) {}
  bool unite(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (-data[y] > -data[x]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool findSet(ll x, ll y) { return root(x) == root(y); }
  ll root(ll x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
  ll size(ll x) { return -data[root(x)]; }
};
