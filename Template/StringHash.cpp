std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
bool isprime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
int findPrime(int n) {
    while (!isprime(n)) n++;
    return n;
}
template <int N> struct StringHash {
    static array<int, N> hash_mod;
    static array<int, N> base;
    vector<array<int, N>> p, h;
    StringHash() {};
    StringHash(const string &s) {
        int n = s.size();
        p.resize(n);
        h.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < N; j++) {
                p[i][j] = 1LL * (i == 0 ? 1LL : p[i - 1][j]) * base[j] % hash_mod[j];
                h[i][j] = (1LL * (i == 0 ? 0LL : h[i - 1][j]) * base[j] + s[i]) % hash_mod[j];
            }
        }
    }
    array<int, N> get(int l, int r) {
        assert(r >= l);
        array<int, N> res{};
        for (int i = 0; i < N; i++) {
            res[i] = (h[r][i] - 1LL * (l == 0 ? 0LL : h[l - 1][i]) * p[r - l][i] % hash_mod[i] + hash_mod[i]) % hash_mod[i];
        }
        return res;
    }
    bool same(int l1, int r1, int l2, int r2) {
        auto res1 = get(l1, r1);
        auto res2 = get(l2, r2);
        for (int i = 0; i < N; i++) {
            if (res1[i] != res2[i]) return false;
        }
        return true;
    }
};
constexpr int HN = 2;
template<> array<int, HN> StringHash<HN>::hash_mod = {
    findPrime(rng() % 900000000 + 100000000),
    findPrime(rng() % 900000000 + 100000000)
};
template<> array<int, HN> StringHash<HN>::base = {13331, 131};
using Hashing = StringHash<HN>;