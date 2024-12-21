template <class info> struct segtree {
#define ls u << 1
#define rs u << 1 | 1
    struct node {
        int l, r;
        info data;
    };

    int n; vector<node> tr;
    segtree(): n(0) {};
    template<typename T> segtree(int n, T v): segtree(vector<T>(n, v)) {}
    template<typename T> segtree(vector<T> a): n(a.size()), tr(n * 4) {
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

    void set(int u, int pos, const info &v) {
        if (tr[u].l == tr[u].r) {
            tr[u].data = v;
            return;
        }
        int mid = (tr[u].l + tr[u].r) / 2;
        if (pos <= mid) set(ls, pos, v);
        else set(rs, pos, v);
        pushup(u);
    }

    void set(int pos, const info &v) {
        set(1, pos, v);
    }

    info qry(int u, int l, int r) {
        if (l <= tr[u].l && tr[u].r <= r) {
            return tr[u].data;
        }
        int mid = (tr[u].l + tr[u].r) / 2;
        if (r <= mid) return qry(ls, l, r);
        if (l >= mid + 1) return qry(rs, l, r);
        return qry(ls, l, r) + qry(rs, l, r);
    }

    info qry(int l, int r) {
        return qry(1, l, r);
    }

    template<typename F>
    int first(int u, int l, int r, F pred) {
        if (l <= tr[u].l && tr[u].r <= r) {
            if (!pred(tr[u].data)) {
                return -1;
            }
            if (tr[u].l == tr[u].r) return tr[u].l;
            if (pred(tr[ls].data)) return first(ls, l, r, pred);
            return first(rs, l, r, pred);
        }
        int mid = (tr[u].l + tr[u].r) / 2;
        if (r <= mid) return first(ls, l, r, pred);
        if (l >= mid + 1) return first(rs, l, r, pred);
        int pos = first(ls, l, r, pred);
        if (pos == -1) pos = first(rs, l, r, pred);
        return pos;
    }

    template <typename F>
    int first(int l, int r, F pred) {
        return first(1, l, r, pred);
    }
    
    template<typename F>
    int last(int u, int l, int r, F pred) {
        if (l <= tr[u].l && tr[u].r <= r) {
            if (!pred(tr[u].data)) {
                return -1;
            }
            if (tr[u].l == tr[u].r) return tr[u].l;
            if (pred(tr[rs].data)) return last(rs, l, r, pred);
            return last(ls, l, r, pred);
        }
        int mid = (tr[u].l + tr[u].r) / 2;
        if (l >= mid + 1) return last(rs, l, r, pred);
        if (r <= mid) return last(ls, l, r, pred);
        int pos = last(rs, l, r, pred);
        if (pos == -1) pos = last(ls, l, r, pred);
        return pos;
    }

    template<typename F>
    int last(int l, int r, F pred) {
        return last(1, l, r, pred);
    }

#undef ls
#undef rs
};

struct info {
    
};
info operator+(const info &a, const info &b) {
    
}