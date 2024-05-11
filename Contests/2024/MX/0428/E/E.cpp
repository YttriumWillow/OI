#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

int n; std::string S;
bool vis[300];

void solve() {
    std::cin >> n >> S;

    i64 cnt = 0, res = 0;
    for (auto ch : S) {
        if (!vis[ch]) ++cnt;
        res += cnt; vis[ch] = 1;
    }

    std::cout << res << '\n';

    memset(vis, 0, sizeof vis);
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) { solve(); }
}