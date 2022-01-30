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

/**
 * @param graph: graph[from_vertice] = [{to_vertice, cost}, ...]
 * @param start: start vertice
 *
 * @return: distance from i to each vertice
 *          INF if not reachable
 *          -INF if negative cycle
 */
vector<ll> bellman_ford(vector<vector<pair<ll, ll>>>& graph, ll start) {
  ll N = graph.size();
  vector<ll> dist(N, INF);
  dist[start] = 0;

  // calculate distance
  for (ll i = 0; i < (N - 1LL) * 2LL; i++) {
    for (ll from = 0; from < N; from++) {
      if (dist[from] >= INF) continue;  // not reachable

      for (auto& [to, cost] : graph[from]) {
        if (chmin(dist[to], dist[from] + cost) && i >= N - 1) {
          dist[to] = -INF;  // negative cycle
        }
      }
    }
  }

  return dist;
}