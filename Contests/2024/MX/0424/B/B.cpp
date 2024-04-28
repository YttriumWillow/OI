#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

int n; char tr[256]; bool u[256];

void solve() {
    std::string S, T;

    std::cin >> S >> T; n = S.size();
    S = '#' + S;  T = '#' + T;

    std::fill(tr, tr + 256, 0);
    std::fill(u, u + 256, 0);

    bool f = true;
    for (int i = 1; i <= n; ++i) {
        if (!tr[S[i]]) {
            if (u[T[i]]) { 
                f = false; break;
            }
            tr[S[i]] = T[i]; u[T[i]] = 1;
        } else if (tr[S[i]] != T[i]) {
            f = false; break;
        }
    }

    std::cout << (f ? "Yes" : "No") << '\n';
}

int main(/*int argc, char const* argv[]*/) {
    // file("cipher");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) { solve(); }
}