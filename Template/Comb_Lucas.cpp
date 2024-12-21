struct Comb {
    int ksm(int a, int k, int p) {
        int res = 1;
        while (k) {
            if (k & 1) res = (i64)res * a % p;
            k >>= 1;
            a = (i64)a * a % p;
        }
        return res;
    }
    int inv(int a, int p) {
        return ksm(a, p - 2, p);
    }
    int C(int n, int m, int p) {
        int res = 1;
        for (int i = 1, j = n; i <= m; i++, j--) {
            res = (i64)res * j % p;
            res = (i64)res * inv(i, p) % p;
        }
        return res;
    }
    int Lucas(i64 n, i64 m, int p) {
        if (n < p && m < p) {
            return C(n, m, p);
        }
        return (i64)C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
    }
} comb;