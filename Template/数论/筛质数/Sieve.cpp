vector<int> minp, primes;
vector<int> fac; // fac[i]: i的素因子的个数
void sieve(int n) {
  minp.assign(n + 1, 0);
  fac.assign(n + 1, 0);
  for (int i = 2; i <= n; i++) {
    if (minp[i] == 0) {
      minp[i] = i;
      fac[i] = 1;
      primes.push_back(i);
    }
    for (auto p : primes) {
      if (i * p > n) break;
      minp[i * p] = p;
      fac[i * p] = fac[i] + 1;
      if (p == minp[i]) break;
    }
  }
}
