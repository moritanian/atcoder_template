#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
bool chmin(ll& a, ll b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const ll INF = 1e18;

template <typename T>
ll dikstra(ll N, ll start, ll goal, vector<vector<ll>>& tbl) {
  vector<T> cost(N, INF);
  cost[start] = 0;
  priority_queue<pair<T, ll>, vector<pair<T, ll>>, greater<pair<T, ll>>> q;
  q.push({0, start});

  while (q.size()) {
    auto [c, i] = q.top();
    q.pop();
    if (c > cost[i]) continue;
    for (auto j : tbl[i]) {
      T next_cost = c + TODO;
      if (chmin(cost[j], next_cost)) q.emplace(cost[j], j);
    }
  }
  return cost[goal];
}

auto func = [&](vector<ll> v1, vector<ll> v2) {
  if (v1[0] == v2[0]) {
    return v1[1] < v2[1];
  }
  return v1[0] > v2[0];
};
priority_queue<vector<ll>, vector<vector<ll>>, decltype(func)> q{func};
