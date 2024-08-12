#include <iostream>
#include <cstring>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define per(i, r, l) for (int i = (r); i >= l; --i)

constexpr int N = 1e2 + 10;
constexpr int inf = 0x3f3f3f3f;

int m, n, s, t;
int stt, res = inf;
bool ava[N][N];
int f[N][N], g[N][N];
// Day i at Room j
// f -> check out times
// g -> prev best Room number 

void path(int l, int r, int room) {
    if (r == t) return;
    if (g[r][room] != room) {
        std::cout << char('A' + room - 1) << ": " << l << '-' << r + 1 << '\n';
        path(r + 1, r + 1, g[r][room]);
    }
    else {
        path(l, r + 1, room);
    }
}

void sol(int T) {
    rep (i, 1, m) rep (j, 1, n) {
        char ch; std::cin >> ch;
        ava[i][j] = (ch == 'O');
    }

    std::cin >> s >> t; f[t][0] = 0;

    per (i, t - 1, s)
        rep (j, 1, n) if (ava[i][j]) rep (k, 0, n) {

        if (f[i][j] > f[i + 1][k] + (j != k)) {
            g[i][j] = k;
            f[i][j] = f[i + 1][k] + (j != k);
        }

    }

    // rep (i, 1, m) rep (j, 1, n)
    //     std::cerr << ava[i][j] << " \n"[j == n];
    // rep (i, 1, m) rep (j, 1, n)
    //     std::cerr << f[i][j] << " \n"[j == n];

    rep (i, 1, n) if (f[s][i] < res) {
        res = f[s][i], stt = i;
    }

    // std::cerr << res << '\n';

    std::cout << "Case " << T << ":\n\n";
    if (res != inf)
        path(s, s, stt);
    else
        std::cout << "Not available\n";
    std::cout << '\n';
}

void cle() {
    res = inf;
    memset(f, 0x3f, sizeof f);  
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T = 0;
    while (std::cin >> m >> n and n) {
        cle(); sol(++T);
    }
}