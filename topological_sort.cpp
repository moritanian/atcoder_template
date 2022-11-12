#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

template <typename T>
vector<T> topological_sort(const vector<vector<T>> &graph) {
  vector<T> ans;
  int N = graph.size();
  vector<int> in_list(N);
  for (int i = 0; i < N; i++) {
    for (auto j : graph[i]) {
      in_list[j]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < N; i++) {
    if (in_list[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int i = q.front();
    ans.push_back(i);
    q.pop();
    for (auto j : graph[i]) {
      in_list[j]--;
      if (in_list[j] == 0) {
        q.push(j);
      }
    }
  }

  return ans;
}

int main() {
  vector<vector<int>> g = {{}, {0}, {3, 0}, {1, 4}, {}};
  auto ans = topological_sort(g);

  for (auto v : ans) {
    cout << v << " ";
  }
  cout << endl;
}