template <unsigned M_> struct ModInt {
    static constexpr unsigned M = M_;
    unsigned x;
    
    constexpr ModInt() = default;
    constexpr ModInt(unsigned x_) : x(x_ % M) {}
    constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
    constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
    constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}

    constexpr ModInt operator++() {
        (*this) += 1; return *this;
    }
    constexpr ModInt operator--() {
        (*this) -= 1; return *this;
    }
    constexpr ModInt operator++(int) {
        const ModInt temp = *this; ++(*this);
        return temp;
    }
    constexpr ModInt operator--(int) {
        const ModInt temp = *this; --(*this);
        return temp;
    }
    ModInt &operator+=(const ModInt &a) {
        x = ((x += a.x) >= M) ? (x - M) : x;
        return *this;
    }
    ModInt &operator-=(const ModInt &a) {
        x = ((x -= a.x) >= M) ? (x + M) : x;
        return *this;
    }
    ModInt &operator*=(const ModInt &a) {
        x = (static_cast<unsigned long long>(x) * a.x) % M;
        return *this;
    }
    ModInt &operator/=(const ModInt &a) {
        return (*this *= a.inv());
    }
    ModInt pow(long long e) const {
        if (e < 0) return inv().pow(-e);
        ModInt a = *this, res = 1U;
        for (; e; e >>= 1, a *= a) { if (e & 1) res *= a; }
        return res;
    }
    ModInt inv() const {
        unsigned a = M, b = x; int y = 0, z = 1;
        for (; b; ) {
            const unsigned q = a / b;
            const unsigned c = a - q * b;
            a = b; b = c;
            const int w = y - static_cast<int>(q) * z;
            y = z; z = w;
        }
        assert(a == 1U);
        return ModInt(y);
    }
    ModInt operator+() const {
        return *this;
    }
    ModInt operator-() const {
        ModInt a; a.x = x ? (M - x) : 0U;
        return a;
    }
    ModInt operator+(const ModInt &a) const {
        return (ModInt(*this) += a);
    }
    ModInt operator-(const ModInt &a) const {
        return (ModInt(*this) -= a);
    }
    ModInt operator*(const ModInt &a) const {
        return (ModInt(*this) *= a);
    }
    ModInt operator/(const ModInt &a) const {
        return (ModInt(*this) /= a);
    }
    template <class T>
    friend ModInt operator+(T a, const ModInt &b) {
        return (ModInt(a) += b);
    }
    template <class T>
    friend ModInt operator-(T a, const ModInt &b) {
        return (ModInt(a) -= b);
    }
    template <class T>
    friend ModInt operator*(T a, const ModInt &b) {
        return (ModInt(a) *= b);
    }
    template <class T>
    friend ModInt operator/(T a, const ModInt &b) {
        return (ModInt(a) /= b);
    }
    explicit operator bool() const {
        return x;
    }
    bool operator==(const ModInt &a) const {
        return (x == a.x);
    }
    bool operator!=(const ModInt &a) const {
        return (x != a.x);
    }
    bool operator<(const ModInt &a) const {
        return (x < a.x);
    }
    bool operator>(const ModInt &a) const {
        return (x > a.x);
    }
    friend std::ostream &operator<<(std::ostream &os, const ModInt &a) {
        return os << a.x;
    }
    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        return is >> a.x;
    }
};
constexpr int Mod = 1e9 + 7;
// constexpr int Mod = 998244353;
using mint = ModInt<Mod>;
