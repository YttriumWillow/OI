#include <iostream>
#include <cstring>
#include <tuple>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 160;
const int mod = 45989;

int n, m, t, P, Q, cnt;
std::pair<int, int> E[N];

struct Mat {
    int r, c, m[N][N];

    int* operator[](int p) { return m[p]; }

    Mat() { memset(m, 0x00, sizeof m); }
    Mat(int r, int c) : r(r), c(c) { memset(m, 0x00, sizeof m); }

    void set() { rep (i, 1, std::min(r, c)) m[i][i] = 1; }

    friend Mat operator * (Mat A, Mat B) {
        Mat res(A.r, B.c);
        rep (i, 1, A.r) rep (j, 1, B.c) rep (k, 1, A.c)
            res[i][j] = (res[i][j] + 1ll * A[i][k] * B[k][j] % mod) % mod;
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
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m >> t >> P >> Q; ++P, ++Q;

    E[++cnt] = { 0, P };

    rep (i, 1, m) {
        int u, v; 
        std::cin >> u >> v; 
        ++u, ++v;
        E[++cnt] = { u, v };
        E[++cnt] = { v, u };
    }

    Mat T(cnt, cnt);

    rep (i, 1, cnt) rep (j, 1, cnt) {
        if (i != j and i != (j ^ 1)) {
            if (E[i].second == E[j].first)
                T[i][j] = 1;
        }
    }

    T = T ^ t;

    int res = 0;
    rep (i, 1, cnt) {
        if (E[i].second == Q) {
            res = (res + T[1][i] % mod) % mod;
        }
    }

    std::cout << res << '\n';

}
