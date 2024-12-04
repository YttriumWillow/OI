#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

constexpr int N = 3e5 + 5;
i64 n, v[N];
i64 cnt1, cnt2, cnt3, sum;

void solve() {
    std::cin >> n;
    rep (i, 1, n) std::cin >> v[i];
    cnt1 = cnt2 = cnt3 = sum = 0;
    rep (i, 1, n) {
        sum += v[i];
        cnt3 += v[i] / 3;
        if (v[i] % 3 == 1) ++cnt1;
        if (v[i] % 3 == 2) ++cnt2;
    }
    if (cnt3 > sum / 4) {
             if (sum % 4 == 0) std::cout << sum / 4 << '\n';
        else if (sum % 4 == 1) std::cout << sum / 4 + 1 << '\n';
        else if (sum % 4 == 2) std::cout << sum / 4 + 1 << '\n';
        else if (sum % 4 == 3) std::cout << sum / 4 + 2 << '\n';
    } else {
        if (cnt3 <= cnt1) {
            std::cout << cnt1 + cnt2 << '\n';
        } else {
            std::cout << cnt2 + cnt3 - (cnt3 - cnt1) / 2 << '\n';
        }
    }
}

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr);
    int T; std::cin >> T;
    while (T--) solve();
}