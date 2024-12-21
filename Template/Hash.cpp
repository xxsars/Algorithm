// 单模hash

const int P = 13331;
const i64 hash_mod = 1610612741;

    string s; s = ' ' + s;
    vector<int> h(n + 1), p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P % hash_mod;
        h[i] = (h[i - 1] * P + s[i]) % hash_mod;
    }

    auto get = [&](int l, int r, vector<int> &h) -> i64 {
        return ((h[r] - h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
    };