
template <typename T>
class Bit {
 public:
  int n;

 public:
  vector<T> bit;
  Bit(int _n) : n(_n + 1), bit(n, 0) {}

  void add(int i, T v) {
    while (i < n) {
      bit[i] += v;
      i += i & (-i);
    }
  }

  T sum(int i) {
    T s(0);
    while (i > 0) {
      s += bit[i];
      i -= i & (-i);
    }
    return s;
  }

  T value(int i) { return sum(i) - sum(i - 1); }
};

// 1 start index
template <typename T>
struct BIT2D {
  int H, W;
  vector<vector<T>> bit;
  BIT2D(int H_, int W_) { init(H_, W_); }
  void init(int H_, int W_) {
    H = H_ + 1;
    W = W_ + 1;
    bit.assign(H, vector<T>(W, 0));
  }
  void add(int h, int w, T x) {
    for (int i = h; i < H; i += (i & -i)) {
      for (int j = w; j < W; j += (j & -j)) {
        bit[i][j] += x;
      }
    }
  }
  // 1≦i≦h かつ 1≦j≦w
  T sum(int h, int w) {
    T s(0);
    for (int i = h; i > 0; i -= (i & -i)) {
      for (int j = w; j > 0; j -= (j & -j)) {
        s += bit[i][j];
      }
    }
    return s;
  }
  // h1≦i<h2 かつ w1≦j<w2
  T query(int h1, int w1, int h2, int w2) {
    return sum(h2 - 1, w2 - 1) - sum(h2 - 1, w1 - 1) - sum(h1 - 1, w2 - 1) +
           sum(h1 - 1, w1 - 1);
  }
};