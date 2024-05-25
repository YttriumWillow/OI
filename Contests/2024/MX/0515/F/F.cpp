#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 2e5 + 10;
constexpr int R = 3e3 + 10;

int B, r1, r2; bool lit[N];
int n, q, k, len, col[N];
std::vector<int> pos[N];

int bcnt, big[N], bdx[N];
int d[N], G[R][R];

void solbig(int c) {
    int p = (lit[c] ^= 1) ? 1 : -1;
    r1 += p * pos[c].size();
    r2 += p * d[c];
    rep (i, 1, bcnt) {
        int u = big[i];
        if (u == c || not lit[u]) continue;
        r2 += p * G[bdx[c]][i];
    }
}

void cal(int u, int v) {
    if (lit[u] and lit[v]) ++r2;
    if (!lit[u] and lit[v]) --r2;
    if (bdx[v]) lit[u] ? ++d[v] : --d[v];
}

void solsmall(int c) {
    int p = (lit[c] ^= 1) ? 1 : -1;
    r1 += p * pos[c].size();
    for (int i = pos[c].size() - 1; i >= 0; --i) {
        int u = pos[c][i];
        if (u < n) cal(col[u], col[u + 1]);
        if (u > 1) cal(col[u], col[u - 1]);
    }
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> q >> k;

    // B = (int)sqrt(n);
    B = 100;
    // B = 100;

    rep (i, 1, n) std::cin >> col[i];

    rep (i, 1, n) {
        while (i < n and col[i] == col[i + 1])
            ++i;
        col[++len] = col[i];
    } n = len;

    rep (i, 1, n) pos[col[i]].push_back(i);
    
    rep (c, 1, k) {
        if (pos[c].size() > B)
            big[bdx[c] = ++bcnt] = c;
    }

    rep (i, 2, n) {
        int& u = bdx[col[i - 1]];
        int& v = bdx[col[i]];
        if (u and v) ++G[u][v], ++G[u][v];
    }

    while (q--) {
        int x; std::cin >> x;
        bdx[x] ? solbig(x) : solsmall(x);
        std::cout << r1 - r2 << '\n';
    }

}