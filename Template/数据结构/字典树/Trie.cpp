struct Trie {
  int idx;
  vector<array<int, 26>> nxt;
  vector<int> cnt;

  Trie(int n) {
    idx = 1;
    nxt.assign(n, {});
    cnt.assign(n, {});
  }

  void insert(string s) {
    int p = 1;
    for (char c : s) {
      int x = c - 'a';
      if (!nxt[p][x]) nxt[p][x] = ++idx;
      p = nxt[p][x]; 
    }
    cnt[p]++;
  }

  int qry(string s) {
    int p = 1;
    for (char c : s) {
      int x = c - 'a';
      if (!nxt[p][x]) return false;
      p = nxt[p][x];
    }
    return cnt[p];
  }
  
  char path[(int)(1E6 + 7)];
  void dfs(int p = 1, int dep = 0) {
    if (cnt[p]) {
      for (int i = 0; i < dep; i++) {
        cout << path[i];
      }
      cout << "\n";
    }
    for (int i = 0; i < 26; i++) {
      if (nxt[p][i]) {
        path[dep] = (char)(i + 'a');
        dfs(nxt[p][i], dep + 1);
      }
    }
  }
};