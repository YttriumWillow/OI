#include <iostream>
#include <cstring>
#include <array>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int M = 10007;

int L;
int P[5][5] = {
    { 0,   0, 0, 0, 0 },

    { 0,   1, 0, 0, 1 },
    { 0,   1, 0, 0, 0 },
    { 0,   0, 1, 0, 0 },
    { 0,   0, 1, 1, 0 }
};

struct Mat {
    int r, c; i64 m[5][5];

    i64* operator[](int p) { return m[p]; }

    Mat() { memset(m, 0x00, sizeof m); }
    Mat(int r, int c) : r(r), c(c) { memset(m, 0x00, sizeof m); }

    void set() { rep (i, 1, std::min(r, c)) m[i][i] = 1; }
    void init() { rep (i, 1, r) rep (j, 1, c) m[i][j] = P[i][j]; }

    friend Mat operator * (Mat A, Mat B) {
        Mat res(A.r, B.c);
        rep (i, 1, A.r) rep (j, 1, B.c) rep (k, 1, A.c)
            res[i][j] = (res[i][j] + A[i][k] * B[k][j] % M) % M;
        return res;
    }
    friend Mat operator ^ (Mat A, int k) {
        Mat res(A.r, A.c); res.set();
        for (; k; k >>= 1) {
            if (k & 1) res = res * A;
            A = A * A;
        }
        return res;
    }
};

int main() {
    file("queue");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> L;
    if (L == 0) { std::cout << 0 << '\n'; return 0; }
    Mat T(4, 4); T.init();
    T[0][0] = 114514;
    T = T ^ (L - 1);
    int res = 0;
    rep (i, 1, 4)
        res = (res + T[i][1] + T[i][2] % M) % M;
    std::cout << res << '\n';
}
