#include <bits/stdc++.h>

#define i64 long long
#define ull unsigned long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr i64 mod = 0x3b800001;

i64 n, r, res; 

void solve() {
    std::string S; std::cin >> n >> S;
    
    if (n == 2) { std::cout << 1 << '\n'; return; }
    if (n == 3) { std::cout << 4 << '\n'; return; }
    i64 res = 1;
    while (n--) res = (res << 1) % mod;
    // if (n & 1) res = (res - 1 + mod) % mod;
    std::cout << res << '\n';
}

int main() {
    int T; std::cin >> T;
    while (T--) solve();
}