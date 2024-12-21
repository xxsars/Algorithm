vector<int> Z(string s) { // (suf of s) & s
    int n = s.size();
    vector<int> z(n);
    z[0] = n; //rule:z[0] = n
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1); //s[i, r] = s[i-l, r-l]
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++; //force
        if (i + z[i] - 1 > r) { //update[l, r]
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

vector<int> P(string s, string t) { // lcp: (suff of s) & t
    auto z = Z(t); // t's pref, so Z(t), careful:TLE
    int n = s.size(), m = t.size();
    vector<int> p(n);
    for (int i = 0, l = 0, r = 0; i < n; i++) {
        if (i != 0 && i <= r) p[i] = min(z[i - l], r - i + 1); // s[i, r] = t[i-l, r-l] 
        while (i + p[i] < n && p[i] < m && s[i + p[i]] == t[p[i]]) p[i]++;
        if (i + p[i] - 1 > r) {
            l = i;
            r = i + p[i] - 1;
        }
    }
    return p;
}