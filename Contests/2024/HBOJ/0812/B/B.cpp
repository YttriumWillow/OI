#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 1e6 + 10;
constexpr int mod = 1e9 + 7;

typedef std::pair<int, int> Pii;

int n, col[N * 3], a[N * 3], buc[N], prv[N * 3];
std::vector<int> pos[N];
std::pair<int, int> f[N * 3];

int solve(int len) {
    f[0] = { 0, 1 };
    rep (i, 1, len) {
        f[i] = { 0, 0 };
        prv[i] = buc[a[i]]; buc[a[i]] = i;
    }
    rep (i, 1, len) {
        if (prv[i]) f[i] = { f[prv[i] - 1].first + 1, f[prv[i] - 1].second };
        if (f[i].first == f[i - 1].first) f[i].second = (f[i].second + f[i - 1].second) % mod;
        else f[i] = max(f[i], f[i - 1]);
    }
    std::fill(buc + 1, buc + n + 1, 0);
    return f[len].first == n - 1 ? f[len].second : 0;
}

int main(/*int argc, char const* argv[]*/) {
    file("circle");
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, 3 * n) {
        std::cin >> col[i];
        pos[col[i]].push_back(i);
    }

    int tot = 0, res = 0;

    // select 0, 1
    tot = 0;
    rep (i, pos[col[1]][1] + 1, 3 * n) a[++tot] = col[i];
    res = (res + solve(tot) % mod) % mod;

    // select 0, 2
    tot = 0;
    rep (i, pos[col[1]][0] + 1, pos[col[1]][2] - 1) a[++tot] = col[i];
    res = (res + solve(tot) % mod) % mod;

    // select 1, 2
    tot = 0;
    rep (i, pos[col[1]][2] + 1, 3 * n) a[++tot] = col[i];
    rep (i, 1, pos[col[1]][1] - 1) a[++tot] = col[i];
    res = (res + solve(tot) % mod) % mod;

    std::cout << res << '\n';
}