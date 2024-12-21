template <typename T> struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) {
        n = n_;
        a.assign(n + 1, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }
    T sum(int x) {
        T res{};
        for (int i = x; i >= 1; i -= i & -i) {
            res = res + a[i];
        }
        return res;
    }
    T query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};