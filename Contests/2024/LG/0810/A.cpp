#include <iostream>
#include <map>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define p first
#define x second

constexpr int N = 2e5 + 5;

int n, m;
std::pair<int, i64> pos[N];

bool solve() {
    std::cin >> n >> m;
    rep (i, 1, m) {
        int pp; i64 aa;
        std::cin >> pp >> aa;
        pos[i] = { pp, aa };
    }

    if (m <= 1) { return 1; }
    if (m == 2) {
        return (pos[2].x - pos[1].x) % (pos[2].p - pos[1].p) == 0;
    }

    std::sort(pos + 1, pos + m + 1);
    if ((pos[2].x - pos[1].x) % (pos[2].p - pos[1].p) != 0) { return 0; }
    i64 d = (pos[2].x - pos[1].x) / (pos[2].p - pos[1].p);
    rep (i, 3, m) {
        if ((pos[i].x - pos[i - 1].x) % (pos[i].p - pos[i - 1].p) != 0) { return 0; }
        i64 t = (pos[i].x - pos[i - 1].x) / (pos[i].p - pos[i - 1].p);
        if (t != d) { return 0; }
    }
    return 1;
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) { std::cout << (solve() ? "Yes" : "No") << '\n'; }
}