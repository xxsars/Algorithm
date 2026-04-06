template <unsigned mod_> struct modular {
  static constexpr unsigned mod = mod_;
  unsigned x;
  constexpr modular() = default;
  constexpr modular(unsigned x_) : x(x_ % mod) {}
  constexpr modular(unsigned long long x_) : x(x_ % mod) {}
  constexpr modular(int x_) : x(((x_ %= static_cast<int>(mod)) < 0) ? (x_ + static_cast<int>(mod)) : x_) {}
  constexpr modular(long long x_) : x(((x_ %= static_cast<long long>(mod)) < 0) ? (x_ + static_cast<long long>(mod)) : x_) {}
  constexpr modular operator++() { (*this) += 1; return *this; }
  constexpr modular operator--() { (*this) -= 1; return *this; }
  constexpr modular operator++(int) { const modular t = *this; ++(*this); return t; }
  constexpr modular operator--(int) { const modular t = *this; --(*this); return t; }
  modular &operator+=(const modular &a) { x = ((x += a.x) >= mod) ? (x - mod) : x; return *this; }
  modular &operator-=(const modular &a) { x = ((x -= a.x) >= mod) ? (x + mod) : x; return *this; }
  modular &operator*=(const modular &a) { x = (static_cast<unsigned long long>(x) * a.x) % mod; return *this; }
  modular &operator/=(const modular &a) { return (*this *= a.inv()); }
  modular pow(long long e) const { if (e < 0) return inv().pow(-e); modular a = *this, res = 1U; for (; e; e >>= 1, a *= a) { if (e & 1) res *= a; } return res; }
  modular inv() const { unsigned a = mod, b = x; int y = 0, z = 1; for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; } assert(a == 1U); return modular(y); }
  modular operator+() const { return *this; }
  modular operator-() const { modular a; a.x = x ? (mod - x) : 0U; return a; }
  modular operator+(const modular &a) const { return (modular(*this) += a); }
  modular operator-(const modular &a) const { return (modular(*this) -= a); }
  modular operator*(const modular &a) const { return (modular(*this) *= a); }
  modular operator/(const modular &a) const { return (modular(*this) /= a); }
  template <class T> friend modular operator+(T a, const modular &b) { return (modular(a) += b); }
  template <class T> friend modular operator-(T a, const modular &b) { return (modular(a) -= b); }
  template <class T> friend modular operator*(T a, const modular &b) { return (modular(a) *= b); }
  template <class T> friend modular operator/(T a, const modular &b) { return (modular(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const modular &a) const { return (x == a.x); }
  bool operator!=(const modular &a) const { return (x != a.x); }
  bool operator<(const modular &a) const { return (x < a.x); }
  bool operator>(const modular &a) const { return (x > a.x); }
  friend ostream &operator<<(ostream &os, const modular &a) { return os << a.x; }
  friend istream &operator>>(istream &is, modular &a) { return is >> a.x; }
};
constexpr int Md = 998244353; using Z = modular<Md>;