#include <iostream>
#include <algorithm>

#define i64 long long 
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e5 + 10;

int n, m, c[N], t[N];
i64 sum[N];

int main(/*int argc, char const *argv[]*/)
{
	file("music");

	std::cin >> n >> m;
	rep (i, 1, n) std::cin >> c[i] >> t[i];

	rep (i, 1, n) {
		sum[i] = sum[i - 1] + 1ll * c[i] * t[i];
	}

	rep (i, 1, m) {
		i64 q; std::cin >> q;
		std::cout << (std::lower_bound(sum + 1, sum + n + 1, q) - sum) << '\n';
	}

	return 0;
}