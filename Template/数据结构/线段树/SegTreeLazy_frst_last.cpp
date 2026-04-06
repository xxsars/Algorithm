#define ls u << 1
#define rs u << 1 | 1
template <class Info, class Tag> struct Lazysegtree {
  struct node {
    int l, r;
    Info info;
    Tag tag;
  };

  int n; vector<node> tr;
  Lazysegtree(): n(0) {};
  template<typename T> Lazysegtree(int n, T v): Lazysegtree(vector<T>(n, v)) {}
  template<typename T> Lazysegtree(vector<T> init): n(init.size() - 1), tr(n * 4) {
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

  void apply(int u, const Tag &v) {
    tr[u].info.apply(v);
    tr[u].tag.apply(v);
  }

  void pushdown(int u) {
    apply(ls, tr[u].tag);
    apply(rs, tr[u].tag);
    tr[u].tag = Tag();
  }

  void set(int u, int pos, const Info &v) {
    if (tr[u].l == tr[u].r) {
      tr[u].info = v;
      return;
    }
    int mid = (tr[u].l + tr[u].r) / 2;
    pushdown(u);
    if (pos <= mid) set(ls, pos, v);
    else set(rs, pos, v);
    pushup(u);
  }

  void set(int pos, const Info &v) {
    set(1, pos, v);
  }

  void modify(int u, int l, int r, const Tag &v) {
    if (l <= tr[u].l && tr[u].r <= r) {
      apply(u, v);
      return;
    }
    int mid = (tr[u].l + tr[u].r) / 2;
    pushdown(u);
    if (l <= mid) modify(ls, l, r, v);
    if (r >= mid + 1) modify(rs, l, r, v);
    pushup(u);
  }

  void modify(int l, int r, const Tag &v) {
    modify(1, l, r, v);
  }

  Info query(int u, int l, int r) {
    if (l <= tr[u].l && tr[u].r <= r) {
      return tr[u].info;
    }
    int mid = (tr[u].l + tr[u].r) / 2;
    pushdown(u);
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

  template<typename F>
  int first(int u, int l, int r, F pred) {
    if (l <= tr[u].l && tr[u].r <= r) {
      if (!pred(tr[u].info)) {
        return -1;
      }
      if (tr[u].l == tr[u].r) return tr[u].l;
      if (pred(tr[ls].info)) return first(ls, l, r, pred);
      return first(rs, l, r, pred);
    }
    int mid = (tr[u].l + tr[u].r) / 2;
    pushdown(u);
    if (r <= mid) return first(ls, l, r, pred);
    if (l >= mid + 1) return first(rs, l, r, pred);
    int pos = first(ls, l, r, pred);
    if (pos == -1) pos = first(rs, l, r, pred);
    return pos;
  }

  template<typename F>
  int first(int u, int l, int r, F pred) {
    if (!pred(tr[u].info)) {
      return -1;
    }
    if (tr[u].l == tr[u].r) {
      return tr[u].l;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) / 2;
    int pos = -1;
    if (l <= mid) {
      pos = first(ls, l, r, pred);
    }
    if (pos == -1 && r >= mid + 1) {
      pos = first(rs, l, r, pred);
    }
    return pos;
  }

  template <typename F>
  int first(int l, int r, F pred) {
    return first(1, l, r, pred);
  }

  template<typename F>
  int last(int u, int l, int r, F pred) {
    if (!pred(tr[u].info)) {
      return -1;
    }
    if (tr[u].l == tr[u].r) {
      return tr[u].l;
    }
    pushdown(u);
    int mid = (tr[u].l + tr[u].r) / 2;
    int pos = -1;
    if (r >= mid + 1) {
      pos = last(rs, l, r, pred);
    }
    if (pos == -1 && l <= mid) {
      pos = last(ls, l, r, pred);
    }
    return pos;
  }

  template<typename F>
  int last(int l, int r, F pred) {
    return last(1, l, r, pred);
  }
};
#undef ls
#undef rs

struct Tag {
  
};
struct Info {
  
};
Info operator+(const Info& l, const Info& r) {
  
}