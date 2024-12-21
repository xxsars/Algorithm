int n, m; cin >> n >> m;
vector<vector<int>> e(n);
vector<int> deg(n);
for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a --, b --;
    e[a].push_back(b);
    deg[b]++;
}
int hh = 0, tt = -1;
for (int i = 0; i < n; i++) {
    if (!deg[i]) {
        q[++tt] = i;
    }
}
while (hh <= tt) {
    int u = q[hh++];
    for (auto x : e[u]) {
        if (--deg[x] == 0) {
            q[++tt] = x;
        }
    }
}
if (tt == n - 1) {
    for (int i = 0; i < n; i++) {
        cout << q[i] + 1 << " \n"[i == n - 1];
    }
} else {
    cout << -1 << endl;
}
