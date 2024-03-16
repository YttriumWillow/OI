#include <iostream>
#include <vector>
#include <tuple>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 3e2 + 10;
const i64 inf = 0x3f3f3f3f;

int n, m;
std::pair<int, int> E[6010];
i64 G[N][N], d[N][N]; i64 cnt[N][N];
i64 Min = 0x3f3f3f3f, res;

int main(/*int argc, char const *argv[]*/) {
	file("b");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m; n = 0;

	rep (i, 1, m) {
		int x, y; std::cin >> x >> y;
		E[i] = { x, y }; 
		n = std::max(n, std::max(x, y));
	}

	rep (i, 1, n) rep (j, 1, n) { G[i][j] = inf; }

	rep (i, 1, m) {
		int x, y; std::tie(x, y) = E[i];
		G[x][y] = G[y][x] = 1; ++cnt[x][y]; ++cnt[y][x];
	}

	rep (i, 1, n) rep (j, 1, n) { d[i][j] = G[i][j]; }


	rep (k, 1, n) {
		rep (i, 1, k - 1) rep (j, 1, i - 1) {
			i64 v = d[i][j] + G[i][k] + G[k][j];
			if ((v < Min) && (v < inf)) {
				Min = v; res = cnt[i][j];
			} else if (v == Min) {
				res += cnt[i][j];
			}
		}
		rep (i, 1, n) rep (j, 1, n) {
			if (d[i][j] > d[i][k] + d[k][j]) {
				d[i][j] = d[i][k] + d[k][j];
				cnt[i][j] = 1ll * cnt[i][k] * cnt[k][j];
			} else if (d[i][j] == d[i][k] + d[k][j]){
				cnt[i][j] += 1ll * cnt[i][k] * cnt[k][j];
			}
		}
	}

	// std::cerr << Min << '\n';
	std::cout << res << '\n';


	return 0;
}