#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 1e5 + 10;

int n, Q, a[N]; i64 sum[N];

int main(/*int argc, char const *argv[]*/) {
	file("four");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> Q;

	rep (i, 1, n) {
		std::cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	rep (i, 1, Q) {
		i64 x; std::cin >> x;
		int res = std::lower_bound(sum + 1, sum + n + 1, x) - sum;
		std::cout << (res <= n ? res : -1) << '\n';
	}

	return 0;
}