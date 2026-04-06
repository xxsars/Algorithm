template<typename T = int> struct XorBase {
  int B, free = 0, rank = 0; bool update = false;
  vector<T> base, nums;

  XorBase(int B = sizeof(T) * 8): B(B), base(B, 0) {}
  bool insert(T x) {
    for (int i = B - 1; i >= 0; i--) {
      if (x >> i & 1) {
        if (base[i] != 0) {
          x ^= base[i];
        } else {
          base[i] = x; rank += 1; update = true;
          return true;
        }
      }
    }
    free += 1;
    return false;
  }

  T qrymin() {
    if (free) return 0;
    for (int i = 0; i < B; i++) {
      if (base[i]) return base[i];
    }
    return 0;
  }

  T qrymax() {
    T x = 0;
    for (int i = B - 1; i >= 0; i--) {
      x = max(x, x ^ base[i]);
    }
    return x;
  }

  T kth(i64 k) {
    assert(k > 0);
    // k >>= free; // 求包含重复值的
    k -= free ? 1 : 0; // 求不包含重复值的
    if (k == 0 && free) return 0;
    if (k >= (1LL << rank)) return -1;
    if (update) {
      nums.clear();
      for (int i = 0; i < B; i++) {
        if (base[i] != 0) nums.push_back(base[i]);
      }
      update = false;
    }
    T x = 0;
    for (int i = rank - 1; i >= 0; i--) {
      if (k >> i & 1)
        x = max(x, x ^ nums[i]);
      else
        x = min(x, x ^ nums[i]);
    }
    return x;
  }

  bool check(T x) {
    for (int i = B - 1; i >= 0; i--) {
      if (x >> i & 1) {
        if (base[i] == 0) return false;
        x ^= base[i];
      }
    }
    return true;
  }

  void merge(const XorBase<T>& other) {
    for (T x : other.base) {
      if (x != 0) insert(x);
    }
    free += other.free;
  }
};