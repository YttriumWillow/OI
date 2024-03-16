#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

int n; std::string S;

void solve() {
    std::cin >> n >> S; S = '#' + S;

    int l = 1, r = n;
    bool f = 0;
    while (l <= r) {
        if (S[l] != S[r]) { f = 1; break; }
        ++l; --r;
    }

    if (f) { std::cout << 1 << '\n'; return; }

    bool f1 = 0, f2 = 0, f3 = 0;

    rep (i, 1, n) {
        if (i > 1 && S[i] != S[i - 1]) {
            f1 = 1;
        }
        if (i > 2 && S[i] != S[i - 2]) {
            f2 = 1;
        }
    }

    int mid = (n >> 1) + 1;
    rep (i, 2, mid - 1) {
        if (S[i] != S[i - 1]) {
            f3 = 1;
        }
    }
    rep (i, mid + 2, n) {
        if (S[i] != S[i - 1]) {
            f3 = 1;
        }
    }

    std::cout << (f1 && f2 && f3 ? 2 : -1) << '\n';
}

int main(/*int argc, char const *argv[]*/) {
    file("string");

    int T; std::cin >> T;
    while (T--) { solve(); }

    return 0;
}