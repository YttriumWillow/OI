#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int n;

int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> n;
    if (n <= 1) { std::cout << -1 << '\n'; return 0; }
    std::cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << '\n';
}