template <typename T, typename Compare = function<T(const T &, const T &)>> struct SparseTable {
    int n;
    vector<vector<T>> ST;
    Compare comp;

    SparseTable(const vector<T> &v): SparseTable(v, [](const T &a, const T &b) {
        return max(a, b);
    }) {}
    SparseTable(const vector<T> &v, const Compare &f): comp(f) {
        n = v.size();
        ST.assign(n, vector<T>(__lg(n) + 1));
        for (int i = 0; i < n; i++) {
            ST[i][0] = v[i];
        }
        for (int j = 1; j <= __lg(n); j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                ST[i][j] = comp(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int j = __lg(r - l + 1);
        return comp(ST[l][j], ST[r - (1 << j) + 1][j]);
    }
};
