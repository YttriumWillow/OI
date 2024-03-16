#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 510;

int C, G[N][N], P;

int main(/*int argc, char const *argv[]*/) {
	file("graph");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> C; P = 1;

	for (; C; ++P) {
		int i = 1; for (; i < P && i * (i - 1) / 2 <= C; ++i)
			G[i][P] = 1;
		C -= (i - 1) * (i - 2) / 2;
	}

	std::cout << P << '\n';

	rep (i, 1, P - 1)  rep (j, i + 1, P) {
		std::cout << (G[i][j] | G[j][i]) << " \n"[j == P];
	}

	return 0;
}