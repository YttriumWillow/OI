#include <iostream>
#include <tuple>
#include <queue>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

const int N = 1e3 + 10;

int n, m, k, res, d[N][N];
char M[N][N];
bool vis[N][N];
int xMov[4] = { 0, -1,  0, 1 };
int yMov[4] = { 1,  0, -1, 0 };

#define OutBound(x, y) (x < 1 or y < 1 or x > n or y > m or M[x][y] == '#')

void bfs(int xS, int yS, int xE, int yE) {
	std::queue<std::tuple<int, int, int>> Q;
	Q.push({ xS, yS, 0 }); vis[xS][yS] = 1;
	while (not Q.empty()) {
		auto u = Q.front(); Q.pop();
		int x, y, D; std::tie(x, y, D) = u;
		if (x == xE and y == yE) { res = D; return; }
		rep (i, 0, 3) {
			rep (l, 1, k) {
				int Tx = x + xMov[i] * l;
				int Ty = y + yMov[i] * l;
				if (OutBound(Tx, Ty)) { break; }
				if (vis[Tx][Ty]) {
					if (d[Tx][Ty] == D + 1) { continue; }
					else { break; }
				}
				d[Tx][Ty] = D + 1; vis[Tx][Ty] = 1;
				Q.push({ Tx, Ty, D + 1 });
			}
		}
	}
}

int main(/*int argc, char const *argv[]*/) {
	file("company");

	std::cin >> n >> m >> k;
	rep (i, 1, n) std::cin >> (M[i] + 1);

	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	bfs(a, b, c, d);
	std::cout << res << '\n';

	return 0;
}