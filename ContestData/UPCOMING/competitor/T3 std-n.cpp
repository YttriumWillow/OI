#include <iostream>
#include <algorithm>
#include <cstring>

#define ull unsigned long long
#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

namespace bufIO {
    const int _Pu = 1 << 16;
    const int _d = 32;
    char buf[_Pu], obuf[_Pu];
    char* inl = buf + _Pu, * inr = buf + _Pu;
    char* outl = obuf, * outr = obuf + _Pu - _d;
    inline void flushin() {
        memmove(buf, inl, inr - inl);
        int rlen = fread(buf + (inr - inl), 1, inl - buf, stdin);
        if (inl - rlen > buf) { buf[inr - inl + rlen] = EOF; }
        inl = buf;
    }
    template <typename _Tp>
    inline void read(_Tp& x) {
        if (inl + _d > inr) { flushin(); }
        int isne = 0;
        for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
        x = (*inl++ - '0');
        for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
        if (isne) { x = -x; }
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
} using namespace bufIO;

constexpr int N = 1.5e5 + 10;

template<typename T>
inline void Radixsort(T *fst, T *lst, T *buf, int *op)
{
	static int b[0x100], i, j;
	int Len = lst - fst, Sz = sizeof(T), at = 0;
	unsigned char *bgn, *end, tmp;
	for (i = 0; i < Sz; ++i)
	{
		if (op[i] == -1) continue;
		bgn = (unsigned char*) fst + i;
		end = (unsigned char*) lst + i;
		tmp = ((op[i] & 1) ? 0xff : 0) ^ ((op[i] & 2) ? 0x80 : 0);
		memset(b, 0, sizeof(b));
		for (unsigned char *it = bgn; it != end; it += Sz) ++b[tmp ^ *it];
		for (j = 1; j < 0x100; ++j) b[j] += b[j - 1];
		for (unsigned char *it = end; it != bgn; buf[--b[tmp^ * (it -= Sz)]] = *--lst);
		lst = buf + Len; std::swap(fst, buf); at ^= 1;
	}
	if (at) memcpy(buf, fst, Sz * Len);
}

#define id(x) (ull)((x) & ((1ull << 32) - 1ull))
#define v(x) (ull)((x) >> 32)

int n, u[N], A[N], B[N], C[N];
int sa, sb, sc;
ull a[N], b[N], c[N], bff[N];

void fix(int v) {
    if (id(a[sa]) == v) u[id(a[sa++])] = 1;
    if (id(b[sb]) == v) u[id(b[sb++])] = 1;
    if (id(c[sc]) == v) u[id(c[sc++])] = 1;
}

int main(/*int argc, char const* argv[]*/) {
    file("craft");

    read(n);
    rep (i, 1, n) {
        int ak, bk, ck; read(ak, bk, ck);
        a[i] |= (ull)ak << 32; a[i] |= i;
        b[i] |= (ull)bk << 32; b[i] |= i;
        c[i] |= (ull)ck << 32; c[i] |= i;
    }
    rep (i, 1, n)
        A[i] = v(a[i]), B[i] = v(b[i]), C[i] = v(c[i]);
    
    Radixsort(a + 1, a + n + 1, bff, new int[8]{ 0, 0, 0, 0, 1, 1, 1, 3 });
    Radixsort(b + 1, b + n + 1, bff, new int[8]{ 0, 0, 0, 0, 1, 1, 1, 3 });
    Radixsort(c + 1, c + n + 1, bff, new int[8]{ 0, 0, 0, 0, 1, 1, 1, 3 });

    while (sa <= n and sb <= n and sc <= n) {
        if (u[id(a[sa])]) { fix(id(a[sa])); continue; }
        if (u[id(b[sb])]) { fix(id(b[sb])); continue; }
        if (u[id(c[sc])]) { fix(id(c[sc])); continue; }
        if (B[id(a[sa])] == v(b[sb])) { fix(id(a[sa])); continue; }
        if (C[id(a[sa])] == v(c[sc])) { fix(id(a[sa])); continue; }
        if (A[id(b[sb])] == v(a[sa])) { fix(id(b[sb])); continue; }
        if (C[id(b[sb])] == v(c[sc])) { fix(id(b[sb])); continue; }
        if (A[id(c[sc])] == v(a[sa])) { fix(id(c[sc])); continue; }
        if (B[id(c[sc])] == v(b[sb])) { fix(id(c[sc])); continue; }
        std::cout << v(a[sa]) + v(b[sb]) + v(c[sc]); return 0;
    }
    std::cout << -1;
    return 0;
}