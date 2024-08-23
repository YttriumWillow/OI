#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e5 + 10;

int n, S, a[N], v[N], res;

bool check(int c) {
    rep (i, 1, n) v[i] = a[i] + i * c;
    std::sort(v + 1, v + n + 1);
    int cnt = 1, val = 0;
    while (cnt <= c and val <= S)
        val += v[cnt++];
    
    return (val <= S) ? (res = val, 1) : 0;
}

int main() {
    std::cin >> n >> S;
    rep (i, 1, n) std::cin >> a[i];

    int l = 0, r = n + 1;

    while (r - l > 1) {
        int mid = l + r >> 1;
        check(mid) ? l = mid : r = mid;
    }

    std::cout << l << ' ' << res << '\n';

}