#include <iostream>
#include <map>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

constexpr int N = 1e5 + 10;

int n, a[N];
std::map<int, int> mp;

void sol() {
    std::cin >> n; 
    rep (i, 1, n) {
        char ch; std::cin >> ch;
        a[i] = (ch - '0' - 1);
    }

    int sum = 0; i64 res = 0;
    rep (i, 1, n) {
        sum += a[i];
        if (sum == 0) ++res;
        res += mp[sum]; ++mp[sum];
    }

    std::cout << res << '\n';
}

void cle() {
    mp.clear();
}

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) {
        cle(); sol();
    }
}