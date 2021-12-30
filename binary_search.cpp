#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

/*
 * list version
 */

vector<ll> list(0, N);
// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
  if (list[index] >= key)
    return true;
  else
    return false;
}

// 汎用的な二分探索のテンプレ
ll search(ll key) {
  ll ng = -1;
  ll ok = list.size();

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (isOK(mid, key))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}

/*
 * lambda version
 */
// TODO check ok is really ok and ng is really ng
ll search(ll key) {
  ll ok = 1;
  ll ng = 100;
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if (isOK(mid, key))
      ok = mid;
    else
      ng = mid;
  }
  return ok;
}
