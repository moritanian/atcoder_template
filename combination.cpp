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
 * Combination prototype declaration
 **/
class CombinationIterator;
class Combination {
  friend CombinationIterator;

 public:
  typedef CombinationIterator iterator;
  Combination::iterator begin();
  Combination::iterator end();
  Combination(int, int);

 private:
  int a;
  int b;
};

/**
 * CombinationIterator prototype declaration
 **/
class CombinationIterator
    : public std::iterator<std::forward_iterator_tag, int> {
  friend Combination;

 private:
  Combination *combination;
  vector<int> list;
  int m_index = 0;
  bool end = false;

  CombinationIterator(Combination *combination, bool is_end = false);
  CombinationIterator(const CombinationIterator &iterator);

 public:
  CombinationIterator &operator++();

  CombinationIterator operator++(int);

  vector<int> operator*();
  bool operator==(const CombinationIterator &iterator);
  bool operator!=(const CombinationIterator &iterator);
};

/**
 * Combination
 **/
Combination::Combination(int a, int b) : a(a), b(b) {}
Combination::iterator Combination::begin() { return CombinationIterator(this); }
Combination::iterator Combination::end() {
  return CombinationIterator(this, true);
}

/**
 * CombinationIterator
 **/
CombinationIterator::CombinationIterator(Combination *combination, bool is_end)
    : combination(combination), m_index(0), end(is_end) {
  list = vector<int>(combination->b);
  for (int i = 0; i < combination->b; i++) {
    list[i] = i;
  }
}

CombinationIterator::CombinationIterator(const CombinationIterator &iterator)
    : combination(iterator.combination),
      list(iterator.list),
      m_index(iterator.m_index) {}

vector<int> CombinationIterator::operator*() { return list; }
CombinationIterator &CombinationIterator::operator++() {
  m_index++;
  int prev = (combination->a);
  int i = list.size() - 1;
  for (; i >= 0; i--) {
    if (list[i] < prev - 1) {
      list[i]++;
      break;
    }
    prev = list[i];
  }

  if (i == -1) {  // end
    end = true;
    return *this;
  }

  i++;
  for (; i < (int)list.size(); i++) {
    list[i] = list[i - 1] + 1;
  }

  return *this;
}

CombinationIterator CombinationIterator::operator++(int) {
  CombinationIterator result = *this;
  ++(*this);

  // m_index++;
  return result;
}

bool CombinationIterator::operator==(const CombinationIterator &iterator) {
  if (this->end != iterator.end) return false;
  if (this->end == iterator.end && this->end) return true;
  return this->combination == iterator.combination &&
         this->m_index == iterator.m_index;
}

bool CombinationIterator::operator!=(const CombinationIterator &iterator) {
  return !(*this == iterator);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto c = Combination(6, 3);
  cout << "6C3" << endl;
  for (auto itr = c.begin(); itr != c.end(); itr++) {
    for (auto v : *itr) cout << v << " ";
    cout << endl;
  }
  // cout << std::fixed << std::setprecision(15) << sqrt(ans) << endl;
}