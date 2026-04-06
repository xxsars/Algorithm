#define ls u << 1
#define rs u << 1 | 1
template <class Info> struct segtree {
  struct node {
    int l, r;
    Info info;
  };

  int n; vector<node> tr;
  segtree(): n(0) {};
  template<typename T> segtree(int n, T v): segtree(vector<T>(n, v)) {}
  template<typename T> segtree(vector<T> init): n(init.size() - 1), tr(n * 4) {
    function<void(int, int, int)> build = [&](int u, int l, int r) -> void {
      tr[u].l = l;
      tr[u].r = r;
      if (l == r) {
        tr[u].info = Info(init[l]);
        return;
      }
      int mid = (l + r) / 2;
      build(ls, l, mid);
      build(rs, mid + 1, r);
      pushup(u);
    };
    build(1, 1, n);
  }

  void pushup(int u) {
    tr[u].info = tr[ls].info + tr[rs].info;
  }

  void set(int u, int pos, const Info &v) {
    if (tr[u].l == tr[u].r) {
      tr[u].info = v;
      return;
    }
    int mid = (tr[u].l + tr[u].r) / 2;
    if (pos <= mid) set(ls, pos, v);
    else set(rs, pos, v);
    pushup(u);
  }

  void set(int pos, const Info &v) {
    set(1, pos, v);
  }

  Info query(int u, int l, int r) {   
    if (l <= tr[u].l && tr[u].r <= r) {
      return tr[u].info;
    }
    int mid = (tr[u].l + tr[u].r) / 2;
    if (r <= mid) return query(ls, l, r);
    if (l >= mid + 1) return query(rs, l, r);
    return query(ls, l, r) + query(rs, l, r);
  }

  Info query(int l, int r) {
    return query(1, l, r);
  }

  Info operator()(int l, int r) {
    return query(l, r);
  }
};
#undef ls
#undef rs

struct Info {
  
};
Info operator+(const Info& l, const Info& r) {
  
}