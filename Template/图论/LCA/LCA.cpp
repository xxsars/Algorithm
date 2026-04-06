struct LCA {
  static constexpr int B = 32;
  int n;
  vector<vector<int>> adj, fa;
  vector<int> dep;
  LCA(const vector<vector<int>>& adj, int rt): n(adj.size()), adj(adj), dep(n), fa(n, vector<int>(B, -1)) {
    function<void(int, int)> dfs = [&](int u, int fr) -> void {
      fa[u][0] = fr;
      for (int i = 1; i < B; i++) {
        fa[u][i] = fa[u][i - 1] == -1 ? -1 : fa[fa[u][i - 1]][i - 1];
      }
      for (auto& v : adj[u]) {
        if (v == fr) {
          continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
      }
    };
    dfs(rt, -1);
  }
  int query(int x, int y) {
    if (dep[x] < dep[y]) {
      swap(x, y);
    }
    for (int i = 0; i < B; i++) {
      if ((dep[x] - dep[y]) >> i & 1) {
        x = fa[x][i];
      }
    }
    if (x == y) {
      return x;
    }
    for (int i = B - 1; i >= 0; i--) {
      if (fa[x][i] != fa[y][i]) {
        x = fa[x][i], y = fa[y][i];
      }
    }
    return fa[x][0];
  }
  int depth(int x) {
    return dep[x];
  }
  int dist(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[query(x, y)];
  }
};
