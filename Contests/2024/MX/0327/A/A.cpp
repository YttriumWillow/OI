#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 2e5 + 10;

int n, a[N];

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> a[i];

    std::cout << (a[1] < a[n] ? "YES" : "NO") << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    file("c");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T; 
    while (T--) { solve(); }
}