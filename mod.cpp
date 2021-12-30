#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <tuple>
#include <vector>
using namespace std;

long long gcd(long long a, long long b) {
  if (a < b) return gcd(b, a);
  if (b == 0) return a;
  return gcd(b, a % b);
}

template <typename T, typename N, typename MOD>
long long modpow(T a, N n, MOD mod) {
  a %= mod;
  T res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

long long extGCD(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

long long modinv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

template <class _MODINT = long long>
class CMath {
 public:
  CMath(int mx = 1e6) : _mx(mx) {
    _fact = vector<_MODINT>(mx + 1, -1);
    _fact[0] = 1;
    _divisors = vector<int>(mx + 1, -1);
    _divisors[1] = 1;
    _numDivisors = vector<int>(mx + 1, -1);
    _numDivisors[1] = 1;
  }

  /**
   * returns a!
   * O(N log (N)): first time
   * O(1): after first time
   */
  _MODINT factorial(int a) {
    if (!_factInitialized) initializeFact();
    return _fact[a];
  }

  /**
   * returns C(a, b)
   * O(N log (N)): first time
   * O(1): after first time
   */
  _MODINT cup(int a, int b) {
    return factorial(a) / factorial(b) / factorial(a - b);
  }

  /**
   * return true if v is a prime number
   * O(N log (N)): first time
   * O(1): after first time
   */
  bool isPrime(int v) {
    if (!_divisorInitialized) initializeDivisor();
    if (v == 1) return false;
    return v == _divisors[v];
  }

  /**
   * return one of the prime divisors (yakusu) of v
   * O(N log (N)): first time
   * O(1): after first time
   */
  int oneDivisor(int v) {
    if (!_divisorInitialized) initializeDivisor();
    return _divisors[v];
  }

  /**
   * return sorted list of the prime divisors (yakusu) of v
   *
   * ex. 12 -> {2, 2, 3}
   * O(N log (N))
   */
  vector<int> primeDivisors(int v) {
    vector<int> res;
    if (!_divisorInitialized) initializeDivisor();
    while (v > 1) {
      res.emplace_back(_divisors[v]);
      v /= _divisors[v];
    }

    reverse(res.begin(), res.end());
    return res;
  }

  /**
   * return the number of divisors (yakusu) of v
   * O(N log (N)): first time
   * O(1): after first time
   */
  int numDivisor(int v) {
    if (!_divisorInitialized) initializeDivisor();
    return _numDivisors[v];
  }

 protected:
  int _mx;
  vector<_MODINT> _fact;
  vector<int> _divisors;
  vector<int> _numDivisors;
  bool _divisorInitialized = false;
  bool _factInitialized = false;
  void initializeFact() {
    if (_factInitialized) return;
    _factInitialized = true;

    for (int i = 1; i <= _mx; i++) {
      _fact[i] = _fact[i - 1] * i;
    }
  }
  void initializeDivisor() {
    if (_divisorInitialized) return;
    _divisorInitialized = true;

    // divisor
    for (int i = 2; i <= _mx; i++) {
      if (_divisors[i] != -1) continue;
      for (ll v = i; v <= _mx; v += i) {
        _divisors[v] = i;
      }
    }

    // num divisor
    for (ll i = 2; i <= _mx; i++) {
      if (isPrime(i)) {  // sosu
        _numDivisors[i] = 2;
      }
      ll v = i;
      ll cnt = 0;
      ll p = _divisors[i];
      while (v % p == 0) {
        v /= p;
        cnt++;
      }
      _numDivisors[i] = _numDivisors[v] * (cnt + 1LL);
    }
  }
};

template <class _MODINT>
class MODMath : public CMath<_MODINT> {
 public:
  MODMath(int mx = 1e6) : CMath<_MODINT>(mx) {
    _vfact = vector<_MODINT>(mx + 1, -1);
  }
  /**
   * returns C(a, b)
   * O(N log (N)): first time
   * O(1): after first time
   */
  _MODINT cup(int a, int b) {
    return (this->factorial(a)) * vfactorial(b) * vfactorial(a - b);
  }

  _MODINT vfactorial(int a) {
    initializeVFact();
    return _vfact[a];
  }

 protected:
  bool _vfactInitialized = false;
  vector<_MODINT> _vfact;

  void initializeVFact() {
    if (this->_vfactInitialized) return;
    this->_vfactInitialized = true;
    if (!this->_factInitialized) this->initializeFact();
    _vfact[this->_mx] = _MODINT(1) / (this->factorial(this->_mx));
    for (int i = this->_mx; i >= 1; i--) {
      _vfact[i - 1] = _vfact[i] * i;
    }
  }
};

template <std::uint_fast64_t Modulus>
class modint {
  using u64 = std::uint_fast64_t;
  using s64 = std::int_fast64_t;

 public:
  u64 a;

  constexpr modint(const s64 x = 0) noexcept
      : a((x >= 0 ? x : ((-x / Modulus) + 1) * Modulus + x) % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }

  constexpr bool operator==(const modint rhs) const noexcept {
    return a == rhs.a;
  }

  modint operator^(s64 n) const {
    modint res = 1;
    modint a = *this;
    while (n > 0) {
      if (n & 1) res *= a;
      a *= a;
      n >>= 1;
    }
    return res;
  }

  // modint pow(const modint n) { return modpow(value(), n.value(), Modulus); }
};

template <std::uint_fast64_t Modulus>
ostream &operator<<(ostream &os, const modint<Modulus> &v) {
  os << v.value();
  return os;
}

const long long Z = 1000000007;
using Mint = modint<Z>;