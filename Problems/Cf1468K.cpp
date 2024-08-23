#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 5005;

std::string S;
int xx, yy;
int x[N], y[N];

void solve() {
    std::cin >> S; x[0] = y[0] = 0;
    int n = S.size(); S = '#' + S;
    rep (i, 1, n) {
        if (S[i] == 'L') x[i] = x[i - 1] - 1, y[i] = y[i - 1];
        if (S[i] == 'R') x[i] = x[i - 1] + 1, y[i] = y[i - 1];
        if (S[i] == 'D') x[i] = x[i - 1], y[i] = y[i - 1] - 1;
        if (S[i] == 'U') x[i] = x[i - 1], y[i] = y[i - 1] + 1;
    }
    rep (i, 1, n) {
        int xx = x[i], yy = y[i]; // 令 (xx, yy) 障碍
        int nx = 0, ny = 0;
        rep (j, 1, n) {
            int dx = 0, dy = 0;
            if (S[j] == 'L') --dx; if (S[j] == 'R') ++dx;
            if (S[j] == 'D') --dy; if (S[j] == 'U') ++dy;
            if (nx + dx == xx && ny + dy == yy) continue;
            nx += dx; ny += dy;
        }
        if (nx == 0 and ny == 0) { std::cout << xx << ' ' << yy << '\n'; return; }
    }
    std::cout << 0 << ' ' << 0 << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
}  