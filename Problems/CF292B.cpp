#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 2e5 + 5;

int n, m, deg[N], cnt[N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m;
    rep (i, 1, m) {
        int u, v; std::cin >> u >> v;
        ++deg[u]; ++deg[v];
    }
    rep (i, 1, n) ++cnt[deg[i]];

    if (cnt[1] == 2 and cnt[2] == n - 2) {
        std::cout << "bus topology" << '\n';
    } else if (cnt[2] == n) {
        std::cout << "ring topology" << '\n';
    } else if (cnt[1] == n - 1 and cnt[n - 1] == 1) {
        std::cout << "star topology" << '\n';
    } else {
        std::cout << "unknown topology" << '\n';;
    }
}