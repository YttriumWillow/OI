#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define sync(b, c) std::ios::sync_with_stdio(b); std::cin.tie(c);

constexpr int N = 1005;

int n, id[N], id2[N];

bool cmp(int x, int y) {
    std::cout << "? " << x << ' ' << y << '\n'; std::cout.flush();
    bool f; std::cin >> f; return f;
}

int main(/*int argc, char const* argv[]*/) {
    sync(false, nullptr); std::cin >> n;
    rep (i, 1, n) id[i] = i;
    std::stable_sort(id + 1, id + n + 1, cmp);
    while (n > 1) {
        std::cout << "+ " << id[1] << ' ' << id[n] << '\n'; std::cout.flush();
        int x; std::cin >> x;
        int l = 1, r = n; while (r - l > 1) {
            int mid = l + r >> 1;
            cmp(x, id[mid]) ? r = mid : l = mid;
        }
        rep (i, 2, l) id2[i - 1] = id[i];
        id2[l] = x;
        rep (i, l + 1, n - 1) id2[i] = id[i];
        rep (i, 1, n) id[i] = id2[i];
        --n;
    }
    std::cout << "!\n"; std::cout.flush();
}