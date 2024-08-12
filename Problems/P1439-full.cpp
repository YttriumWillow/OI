#include <iostream>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e5 + 10;
constexpr int inf = 0x3f3f3f3f;

int n, a[N], b[N];
int mp[N], f[N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) {
        std::cin >> a[i];
        mp[a[i]] = i;
    }
    rep (i, 1, n) {
        std::cin >> b[i];
        f[i] = inf;
    }

    f[0] = 0; int len = 0;

    rep (i, 1, n) {
        int l = 0, r = len;
        if (mp[b[i]] > f[len])
            f[++len] = mp[b[i]];
        else {
            while (l < r) {
                int mid = (l + r) >> 1;
                f[mid] > mp[b[i]] ? r = mid : l = mid + 1;
            }
            f[l] = std::min(mp[b[i]], f[l]);
        }
    }

    std::cout << len << '\n';
}