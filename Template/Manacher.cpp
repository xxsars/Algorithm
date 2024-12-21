// Max Palindrome String: s.substr((i - p[i]) / 2, p[i] - 1) <=> [(i - p[i]) / 2, (i - p[i]) / 2 + p[i] - 1 - 1];
vector<int> manacher(string s) {
    string t = "$#";
    for (auto c : s) {
        t += c;
        t += '#';
    }
    t += "^";
    int n = t.size();
    vector<int> r(n);
    int mid = 0, Rmax = 0;
    for (int i = 0; i < n; i++) {
        if (i < Rmax) r[i] = min(r[2 * mid - i], Rmax - i);
        while (i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) r[i]++;
        if (i + r[i] > Rmax) {
            mid = i;
            Rmax = i + r[i];
        }
    }
    return r;
}