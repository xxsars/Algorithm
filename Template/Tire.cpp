struct Tire {
    int idx;
    vector<array<int, 26>> nxt;
    vector<int> isend;
    Tire() {}
    Tire(int n) {
        init(n);
    }
    void init(int n) {
        idx = 0;
        nxt.assign(n, {});
        isend.assign(n, {});
    }
    void insert(string s) {
        int n = s.size();
        int now = 0;
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            if (!nxt[now][x]) nxt[now][x] = ++idx;
            now = nxt[now][x]; 
        }
        isend[now] = true;
    }
    bool qry(string s) {
        int n = s.size();
        int now = 0;
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            if (!nxt[now][x]) return false;
            now = nxt[now][x];
        }
        return isend[now];
    }
    // 字典序输出字符串
    array<int, 105> a;
    void dfs(int now, int depth) {
        if (isend[now]) {
            for (int i = 0; i < depth; i++) {
                cout << (char)(a[i] + 'a');
            }
            cout << "\n";
        }
        for (int i = 0; i < 26; i++) {
            if (nxt[now][i]) {
                a[depth] = i;
                dfs(nxt[now][i], depth + 1);
            }
        }
    }
    void dfs() {
        dfs(0, 0);
    }
};