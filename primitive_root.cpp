
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
template <typename T, typename N, typename MOD>
long long modpow(T a, N n, MOD mod) {
  T res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

/**
 *  TODO: 未検証
 */
ll compute_min_primitive_root(ll p) {
  /**
   * prime factorization
   */
  vector<ll> v;
  for (ll i = 2; i * i <= p - 1; i++) {
    if (p % i != 0) continue;
    v.push_back(i);
    while (p % i == 0) {
      p /= i;
    }
  }

  /**
   * find primitive root
   */

  auto check_primitive_root = [&](ll x) {
    for (auto j : v) {
      if (modpow(x, (p - 1) / j, p) == 1) {
        return false;
      }
    }
    return true;
  };

  for (ll i = 2; i <= p - 1; i++) {
    if (check_primitive_root(i)) {
      return i;
    }
  }

  throw runtime_error("not found");
}