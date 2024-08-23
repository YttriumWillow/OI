#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

constexpr int N = 3e3 + 5;

int n, a[N];

std::set<int> g;

void dfs(int u) {
    
}

int main(/*int argc, char const* argv[]*/) {
    file("grass");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    std::sort(a + 1, a + n + 1, std::greater<int>());
    
    dfs(1);
}