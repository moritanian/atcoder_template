vector<ll> compress(vector<ll> &list) {
  vector<ll> l = list;
  sort(l.begin(), l.end());
  auto e = unique(l.begin(), l.end());
  l.erase(e, l.end());
  vector<ll> res;
  for (ll v : list) {
    res.push_back(lower_bound(l.begin(), l.end(), v) - l.begin());
  }
  return res;
}