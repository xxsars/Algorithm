// 返回s中匹配模式串p的下标
vector<int> kmp(string &s, string &p) {
  vector<int> a;
  int n = s.size(), m = p.size();
  vector<int> ne(m);
  ne[0] = -1;
  for (int i = 1, j = -1; i < m; i++) {
    while (j >= 0 && p[j + 1] != p[i]) j = ne[j];
    if (p[j + 1] == p[i]) j++;
    ne[i] = j;
  }
  for (int i = 0, j = -1; i < n; i++) {
    while (j != -1 && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m - 1) {
      a.push_back(i - j);
      j = ne[j];
    }
  }
  return a;
}