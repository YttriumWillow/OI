#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

i64 n, s;

bool check(i64 c) {
    i64 o = c, cnt = 0;
    while (c) {
        cnt += c % 10;
        c /= 10;
    }
    return o - cnt < s;
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> s;
    i64 l = 1, r = n + 1;
    while (r - l > 1) {
        i64 mid = l + r >> 1;
        check(mid) ? l = mid : r = mid;
    }
    std::cout << n - l << '\n';
}