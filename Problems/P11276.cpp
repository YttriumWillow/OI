#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

constexpr int N = 1e6 + 5;
std::string S; int n, fail[N];

int main() {
    sync(false, nullptr);
    std::cin >> S; n = S.size(); S = '#' + S;

    int j = 0; fail[0] = 1;
    rep (i, 2, n) {
        while (j > 0 && S[i] != S[j + 1]) j = fail[j];
        if (S[i] == S[j + 1]) ++j;
        fail[i] = j;
    }

    rep (i, 1, n)
        std::cout << S[i];
    for (int i = fail[n] + 1; i <= n; ++i)
        std::cout << S[i];
}