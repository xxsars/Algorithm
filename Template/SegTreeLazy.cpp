template <class info, class tag> struct lazysegtree {
#define ls u << 1
#define rs u << 1 | 1
    struct node {
        int l, r;
        info data;
        tag tg;
    };

    int n; vector<node> tr;
    lazysegtree(): n(0) {};
    template<typename T> lazysegtree(int n, T v): lazysegtree(vector<T>(n, v)) {}
    template<typename T> lazysegtree(vector<T> a): n(a.size()), tr(n * 4) {
        a.resize(n + 1);
        for (int i = n; i >= 1; i--) a[i] = a[i - 1];
        function<void(int, int, int)> build = [&](int u, int l, int r) -> void {
            tr[u].l = l;
            tr[u].r = r;
            if (l == r) {
                tr[u].data = info(a[l]);
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
        tr[u].data = tr[ls].data + tr[rs].data;
    }

    void apply(int u, const tag &v) {
        tr[u].data.apply(v);
        tr[u].tg.apply(v);
    }

    void pushdown(int u) {
        apply(ls, tr[u].tg);
        apply(rs, tr[u].tg);
        tr[u].tg = tag();
    }

    void set(int u, int pos, const info &v) {
        if (tr[u].l == tr[u].r) {
            tr[u].data = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) / 2;
        pushdown(u);
        if (pos <= mid) set(ls, pos, v);
        else set(rs, pos, v);
        pushup(u);
    }

    void set(int pos, const info &v) {
        set(1, pos, v);
    }

    void modify(int u, int l, int r, const tag &v) {
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

    void modify(int l, int r, const tag &v) {
        modify(1, l, r, v);
    }

    info qry(int u, int l, int r) {
        if (l <= tr[u].l && tr[u].r <= r) {
            return tr[u].data;
        }
        int mid = (tr[u].l + tr[u].r) / 2;
        pushdown(u);
        if (r <= mid) return qry(ls, l, r);
        if (l >= mid + 1) return qry(rs, l, r);
        return qry(ls, l, r) + qry(rs, l, r);
    }

    info qry(int l, int r) {
        return qry(1, l, r);
    }

#undef ls
#undef rs
};

struct tag {
    
};
struct info {
    
};
info operator+(const info &a, const info &b) {
    
}