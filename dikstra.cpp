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

ll dikstra(ll N, ll start, ll goal, vector<vector<ll>>& tbl) {
  vector cost(N, INF);
  cost[start] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> q;
  while (q.size()) {
    auto [c, i] = q.top();
    q.pop();
    if (c > cost[i]) continue;
    for (auto j : tbl[i]) {
      ll next_cost = c + TODO;
      if (chmin(cost[j], next_cost)) q.emplace(cost[j], j);
    }
  }
  return cost[goal];
}
