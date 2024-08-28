#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e6 + 5;
int n, a[N]; i64 m;

bool check(int c) {
    i64 sum = 0;
    rep (i, 1, n) if (a[i] >= c) sum += a[i] - c;
    return sum >= m;
}

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n >> m;
    rep (i, 1, n) std::cin >> a[i];

    int l = 0, r = 4e5 + 5;
    while (r - l > 1) {
        int mid = l + r >> 1;
        check(mid) ? l = mid : r = mid;
    }    
    std::cout << l << '\n';
}