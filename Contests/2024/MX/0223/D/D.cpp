#include <bits/stdc++.h>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

typedef unsigned long long ull;

int n, k;
ull a[4000005], ans, U, seed;
ull res[110];

int main(/*int argc, char const *argv[]*/) {
	// file("bing")

	scanf("%d%llu%d", &n, &seed, &k);
	srand(seed);
	U = (k == 64 ? 0ull : (1ull << k)) - 1ull;
	std::mt19937_64 rnd(seed);
	for(int i = 1; i <= n; i++) a[i] = rnd() & U;

    rep (_, 0, k - 1) {
    	ull S = 1ull << _;
    	ull cnt0 = 0, cnt1 = 0;

    	rep (i, 1, n) {
    		if (a[i] & S) {
    			res[_] += (i - 1) * (i - 2) / 2; ++cnt1;
    		} else {
    			res[_] += cnt0 * cnt1; ++cnt0;
    		}
    	}
    }

    per (_, k - 1, 0) {
    	ans = (ans << 1ull) + res[_];
    }

    std::cout << ans << '\n';

	return 0;
}