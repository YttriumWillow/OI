// A not very long common subsequence.

#include <iostream>
#include <cstring>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

const int N = 1e6 + 10;
const int M = 1e3 + 10;
const int inf = 0x3f3f3f3f;

int n, m;
std::string A, B;
int nxt[N][26]; // nxt[i][c] 表示字符 c 在 A 中下一个出现的位置。
int f[M][M]; // f[i][j] 表示 B 的前缀 [1..i] 匹配了 j 位需要在 A 中匹配到的最前位置。 有点难懂？

int main(/*int argc, char const *argv[]*/) {
	file("vlcs");

	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> A; n = A.size(); A = '#' + A;
	std::cin >> B; m = B.size(); B = '#' + B;

	rep (c, 0, 25) {
		int cur = inf;
		per (j, n, 0) {
			nxt[j][c] = cur;
			if (c == A[j] - 'a') cur = j;
		}
	}

	rep (i, 0, m) rep (j, 0, m) f[i][j] = inf;

	rep (i, 0, m) f[i][0] = 0;

	rep (i, 1, m) {
		rep (j, 1, i) {
			f[i][j] = f[i - 1][j];
			if (f[i - 1][j - 1] <= n)
				f[i][j] = std::min(f[i][j], nxt[f[i - 1][j - 1]][B[i] - 'a']);
		}
	}

	int res = 0;
	rep (i, 1, m) {
		if (f[m][i] >= inf) break;
		res = i;
	}

	std::cout << res << '\n';

	return 0;
}