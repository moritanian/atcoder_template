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

/**
 * Hadamard tranform
 *
 * normalization term is not included!!
 * divide by sqrt(a.size()) : a.size() is 2^k
 */
template <typename T>
void hadamard_transform(vector<T> &a) {
  for (int i = 1; i < a.size(); i <<= 1) {
    for (int j = 0; j < a.size(); j++) {
      if ((j & i) == 0) {
        T x = a[j];
        T y = a[j | i];
        a[j] = x + y;
        a[j | i] = x - y;
      }
    }
  }
}

template <typename T>
vector<T> exor_convolution(vector<T> a, vector<T> b) {
  int K = a.size();
  hadamard_transform(a);
  hadamard_transform(b);
  for (int i = 0; i < K; i++) {
    a[i] *= b[i];
  }
  hadamard_transform(a);
  for (int i = 0; i < K; i++) {
    a[i] /= K;
  }
  return a;
}

int main() {
  vector<int> a{1, 0, 2, 0};
  vector<int> b{0, 1, 0, 2};
  vector<int> c = exor_convolution(a, b);
  for (int i = 0; i < c.size(); i++) {
    cout << c[i] << endl;
  }
}