
ll tento(const vector<ll> &L) {
  atcoder::fenwick_tree<ll> ft(L.size());
  ll ans = 0;
  REP(i, L.size()) {
    ans += ft.sum(L[i], L.size());
    ft.add(L[i], 1);
  }
  return ans;
}

vector<ll> compress(const vector<ll> &X) {
  vector<pair<ll, ll>> ps;
  REP(i, X.size()) { ps.emplace_back(X[i], i); }
  sort(ALL(ps));

  vector<ll> ans(X.size());
  REP(i, X.size()) { ans[ps[i].second] = i; }

  return ans;
}