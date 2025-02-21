namespace Fast_IO {
    const int MAXL((1 << 18) + 1); int iof, iotp;
    char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL], *iooS = ioof, *iooT = ioof + MAXL - 1, ioc, iost[55];
    char Getchar() {
        if (ioiS == ioiT) {
            ioiS = ioif; ioiT = ioiS + fread(ioif, 1, MAXL, stdin);
            return (ioiS == ioiT ? EOF : *ioiS++);
        }
        else return (*ioiS++);
    }
    void Write() {
        fwrite(ioof, 1, iooS - ioof, stdout);
        iooS = ioof;
    }
    void Putchar(char x) {
        *iooS++ = x;
        if (iooS == iooT) Write();
    }
    inline int read() {
        int x = 0;
        for (iof = 1, ioc = Getchar(); (ioc < '0' || ioc > '9') && ioc != EOF;) iof = ioc == '-' ? -1 : 1, ioc = Getchar();
        if (ioc == EOF) Write(), exit(0);
        for (x = 0; ioc <= '9' && ioc >= '0'; ioc = Getchar()) x = (x << 3) + (x << 1) + (ioc ^ 48);
        return x * iof;
    }
    inline long long read_ll() {
        long long x = 0;
        for (iof = 1, ioc = Getchar(); (ioc < '0' || ioc > '9') && ioc != EOF;) iof = ioc == '-' ? -1 : 1, ioc = Getchar();
        if (ioc == EOF) Write(), exit(0);
        for (x = 0; ioc <= '9' && ioc >= '0'; ioc = Getchar()) x = (x << 3) + (x << 1) + (ioc ^ 48);
        return x * iof;
    }
    void Getstr(char *s, int &l) {
        for (ioc = Getchar(); ioc == ' ' || ioc == '\n' || ioc == '\t';) ioc = Getchar();
        if (ioc == EOF) Write(), exit(0);
        for (l = 0; !(ioc == ' ' || ioc == '\n' || ioc == '\t' || ioc == EOF); ioc = Getchar()) s[l++] = ioc;
        s[l] = 0;
    }
    template <class Int>
    void Print(Int x, char ch = '\0') {
        if (!x) Putchar('0');
        if (x < 0) Putchar('-'), x = -x;
        while (x) iost[++iotp] = x % 10 + '0', x /= 10;
        while (iotp) Putchar(iost[iotp--]);
        if (ch) Putchar(ch);
    }
    void Putstr(const char *s) {
        for (int i = 0, n = strlen(s); i < n; ++i) Putchar(s[i]);
    }
} // namespace Fast_IO
using namespace Fast_IO;
