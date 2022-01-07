#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<int> kmp(const T &a, const T &b) {
  vector<int> ret;
  int size_a = a.size();
  int size_b = b.size();

  vector<int> nxt(size_b + 1, 0);
  nxt[0] = -1;
  int j = nxt[0];

  // calculate nxt
  for (int i = 0; i < size_b; i++) {
    while (j >= 0 && b[i] != b[j]) j = nxt[j];
    j++;

    // skip b[i] == b[nxt[i]]
    if (i < size_b - 1 && b[i + 1] == b[j]) {
      nxt[i + 1] = nxt[j];
    } else {
      nxt[i + 1] = j;
    }
  }

  // search
  int i_a = 0;
  int i_b = 0;
  while (i_a < size_a) {
    if (a[i_a] == b[i_b]) {  // match
      i_a++;
      i_b++;
      if (i_b == size_b) {
        ret.emplace_back(i_a - size_b);
        i_b = nxt[i_b];
      }
    } else if (nxt[i_b] == nxt[0]) {  // top
      i_a++;
      i_b = 0;
    } else {
      i_b = nxt[i_b];
    }
  }

  return ret;
}

int main() {
  auto ret = kmp(string("abacabacabacabad"), string("abacabacabad"));
  for (auto &i : ret) {
    cout << i << endl;
  }
}