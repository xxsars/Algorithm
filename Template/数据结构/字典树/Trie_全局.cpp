constexpr int N = 1E6 + 7;

int idx = 1;
int nxt[N][26];
int cnt[N];

void insert(string s) {
  int p = 1;
  for (char c : s) {
    int x = c - 'a';
    if (!nxt[p][x]) nxt[p][x] = ++idx;
    p = nxt[p][x];
  }
  cnt[p]++;
}

int query(string s) {
  int p = 1;
  for (char c : s) {
    int x = c - 'a';
    if (!nxt[p][x]) return 0;
    p = nxt[p][x];
  }
  return cnt[p];
}

char path[N];
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