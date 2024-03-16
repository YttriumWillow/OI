#include <iostream>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 310;

int n, m, x, y;
bool M[N][N];

void bfs(int x, int y) {
	
}
 
int main(/*int argc, char const *argv[]*/) {
	file("island");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m >> X >> Y;

	rep (i, 1, n) {
		char ch; std::cin >> ch;
		M[i][j] = ch - '0';
		if (not M[i][j]) { col[i][j] = -1; }
	}

	rep (i, 1, n) rep (j, 1, n) 
		if (not col[i][j])
			bfs(i, j);

	return 0;
}