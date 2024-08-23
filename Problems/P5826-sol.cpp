#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;
int t, n, q, m, a[N];
std::vector<int> pos[N];

int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> t >> n >> q >> m;
    rep (i, 1, n) {
        int x; std::cin >> x;
        pos[x].push_back(i);
    }
    while (q--) {
        int k; std::cin >> k;
        bool f = 1; int cur = 0;
        while (k--) {
            int x; std::cin >> x;
            if (!f) continue;
            auto it = std::lower_bound(pos[x].begin(), pos[x].end(), cur + 1);
            it == pos[x].end() ? f = 0 : cur = *it;
        }
        std::cout << (f ? "Yes" : "No") << '\n';
    }

}