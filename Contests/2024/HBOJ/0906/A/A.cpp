#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

int n, m;

int main(/*int argc, char const* argv[]*/) {
    // file("game");
    std::cin >> n >> m;
    std::cout << (m != 0 ? "Alice" : "Bob") << '\n';
}