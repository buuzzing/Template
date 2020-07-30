template<class _Ty> inline void read(_Ty& x) {
    static _Ty c, s;
    x = 0, s = 1;
    c = getchar();
    if (c == '-')s = -1;
    else x = x * 10 + c - '0';
    for (;;) {
        c = getchar();
        if (!isdigit(c))break;
        x = x * 10 + c - '0';
    }
    x *= s;
}

template<class _Ty> inline void write(_Ty x) {
    static int c[64];
    unsigned p = 0;
    if (x < 0) {
        putchar('-'), x = -x;
    }
    if (x == 0) {
        putchar('0');
        return;
    }
    while (x) {
        c[++p] = x % 10 + '0', x /= 10;
    }
    while (p) {
        putchar(c[p]);
        --p;
    }
}
