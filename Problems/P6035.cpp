#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define offsync() std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

constexpr int N = 1e6 + 5;
constexpr int mod = 1e9 + 7;

int n, res = 1, a[N], b[N];

// class BalancedTree {
//     std::vector<int> t; std::vector<int>::iterator cur;
// public:
//     BalancedTree(int *a, int n) {
//         rep (i, 1, n) t.push_back(a[i]);
//         std::sort(t.begin(), t.end());
//     }
//     void locate(int x) { cur = lower_bound(t.begin(), t.end(), x); }
//     void insert(int x) { locate(x); t.insert(cur, x); }
//     void remove(int x) { locate(x); t.erase(cur); }
//     int kth(int x) { return t.at(x - 1); }
// };

__gnu_pbds::tree<int, __gnu_pbds::null_type, std::less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> T;
void remove(int x) {
	T.erase(T.lower_bound(x));
}
int kth(int k) {
	return *T.find_by_order(k - 1);
}

int main(/*int argc, char const* argv[]*/) {
    offsync(); std::cin >> n;
    rep (i, 1, n) std::cin >> b[i];
    rep (i, 1, n) T.insert(i);
    rep (i, 1, n) {
        if (b[i] + 1 > n - i + 1) { std::cout << 0; return 0; }
        (~b[i]) ? (a[i] = kth(b[i] + 1)) : ((a[i] = kth(1)), (res = 1ll * res * (n - i + 1) % mod));
        remove(a[i]);
    }
    std::cout << res << '\n';
    rep (i, 1, n) std::cout << a[i] << ' ';
}