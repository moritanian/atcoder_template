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

// g: vector<vector<array<ll, 3>>>
void dikstra() {
  // X -> Y の探索
  vector cost(N, INF);
  cost[X] = 0;  // initial value
  priority_queue q(greater<>{}, vector{pair{ll{}, X}});
  while (q.size()) {
    auto [c, at] = q.top();
    q.pop();
    if (c > cost[at]) continue;
    for (auto& [to, v1, v2] : g[at])
      if (chmin(cost[to], get_cost(c, v1, v2)) q.emplace(cost[to], to);
  }
  ll ans = cost[Y];
}
