#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 205;

int n, rt, p[N], q[N];
int T[N][2], fa[N];

i64 dfs(int u) {
    if (!u) return 1;
    i64 lc = p[u] * dfs(T[u][0]);
    i64 rc = q[u] * dfs(T[u][1]);
    i64 lcm = lc * rc / std::__gcd(lc, rc);
    return lcm / p[u] + lcm / q[u];
}

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n;
    rep (i, 1, n) {
        int r, b;
        std::cin >> p[i] >> q[i] >> r >> b;
        T[i][0] = r; fa[r] = i;
        T[i][1] = b; fa[b] = i;
    }

    rep (i, 1, n) if (!fa[i]) { rt = i; break; }

    std::cout << dfs(rt) << '\n';
}