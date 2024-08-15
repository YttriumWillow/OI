#include <iostream>
#include <map>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout); std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 2e5 + 5;

typedef std::pair<int, int> Pii;

int n; Pii a[N];

int main(/*int argc, char const* argv[]*/) {
    file("pair");

    std::cin >> n;
    rep (i, 1, n) {
        int p, q; std::cin >> p >> q;
        a[i] = { p, q };
    }
    
}