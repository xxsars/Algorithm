struct Dsu { // 如果iddex = 1, cc初始化为n - 1
  vector<int> f, siz; int cc;
  Dsu(int n): f(n), siz(n, 1), cc(n) { iota(f.begin(), f.end(), 0); }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return siz[find(x)]; }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] > siz[y]) swap(x, y);
    siz[y] += siz[x];
    f[x] = y;
    cc -= 1;
    return true;
  }
};
