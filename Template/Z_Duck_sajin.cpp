template <class T> struct z_function {
    const T s; /// start-hash
    int n;
    vector<int> z;
 
    z_function(const T &s) : s(s), n(s.size()), z(n) {
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            z[i] = max(0, min(z[i - l], r - i));
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
    } /// end-hash
 
    vector<int> cal(const T &t) { /// start-hash
        int m = t.size();
        vector<int> res(m);
        int l = 0, r = 0;
        for (int i = 0; i < m; ++i) {
            res[i] = max(0, min(i - l < n ? z[i - l] : 0, r - i));
            while (i + res[i] < m && s[res[i]] == t[i + res[i]]) res[i]++;
            if (i + res[i] > r) {
                l = i;
                r = i + res[i];
            }
        }
        return res;
    } /// end-hash
};