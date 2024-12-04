#include <bits/stdc++.h>

#define i64 long long 
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

typedef std::array<int, 2> pii;
constexpr int N = 4e3 + 5;
int n, x[N], y[N];
char s[N][N];
// int res[N][N];

bool play() {
    std::priority_queue<pii> Q;
    rep (i, 1, n) if (y[i] != 0) Q.push({ y[i], i });

    rep (i, 1, n) {
        if (x[i] < 0) return false;
        std::vector<pii> v;
        rep (j, 1, x[i]) {
            if (Q.empty()) return false;
            auto u = Q.top(); Q.pop();
            if (u[0] != 1) v.push_back({ u[0] - 1, u[1] });
            // res[i][u[1]] = 1;
        }
        for (auto P : v) Q.push(P);
    }
    return Q.empty();
}

void solve() {
    std::cin >> n;
    rep (i, 1, n) rep (j, 1, n) std::cin >> s[i][j];
    rep (i, 1, n) std::cin >> x[i];
    rep (i, 1, n) std::cin >> y[i];
    rep (i, 1, n) rep (j, 1, n) {
        if (s[i][j] == '-') {
            ++x[i]; ++y[j];
        }
    }

    std::cout << (play() ? "Yes" : "No") << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    file("game");
    int T; std::cin >> T;
    while (T--) solve();
}