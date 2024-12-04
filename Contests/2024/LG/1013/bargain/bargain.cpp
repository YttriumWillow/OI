#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 1e5 + 10;
constexpr int inf = 1e7;

std::string S; int v[10]; i64 res = inf;
std::vector<int> b; bool rm[N];

inline void dfs(int i) {
    // del the numcode i
    if (i == 10) {
        i64 sum = 0;
        for (auto bit : b) {
            if (sum > inf) break;
            if (!rm[bit]) sum = sum * 10 + bit;
        }
        rep (bit, 0, 9) if (rm[bit]) sum += v[bit];
        res = std::min(res, sum);
        return;
    }
    rm[i] = 1; dfs(i + 1);
    rm[i] = 0; dfs(i + 1);
}

void solve() {
    std::cin >> S; res = inf;
    rep (i, 0, 9) std::cin >> v[i];
    for (auto cur : S) b.push_back(cur - '0');
    std::reverse(b.begin(), b.end());
    dfs(0); dfs(1); std::cout << res << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    // file("bargain");
    sync(false, nullptr);
    int c, T; std::cin >> c >> T;
    while (T--) solve();
}