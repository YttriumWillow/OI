#include <bits/stdc++.h>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 5e5 + 5;
typedef std::pair<int, int> Pii;
int n; Pii a[N], b[N], c[N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) {
        std::cin >> a[i].first >> a[i].second;
        b[i] = c[i] = a[i];
    }
    std::sort(b + 1, b + n + 1);
    std::sort(c + 1, c + n + 1, [](const Pii& A, const Pii& B) { return A.second < B.second; });

    i64 sum = 0;
    rep (i, 1, n) {
        int l, r, mid;
        l = 0, r = n + 1;
        while (r - l > 1) {
            mid = l + r >> 1;
            b[mid].first > a[i].second ? r = mid : l = mid;
        }
        sum += n - r + 1;
        l = 0, r = n + 1;
        while (r - l > 1) {
            mid = l + r >> 1;
            c[mid].second < a[i].first ? l = mid : r = mid;
        }
        sum += l;
    }
    sum >>= 1;
    std::cout << (1ll * n * (n - 1) / 2 - sum) << '\n';
}