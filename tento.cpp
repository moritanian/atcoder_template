
template <typename T>
int tento(vector<T>& V) {
  atcoder::fenwick_tree<ll> ft(L.size());
  int ans = 0;
  for (int i = 0; i < L.size(); i++) {
    ans += ft.sum(L[i], L.size());
    ft.add(L[i], 1);
  }
  return ans;
}
