#include <iostream>

#define i64 long long
#define ull unsigned i64
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

#define lowbit(x) ((x) & -(x))

constexpr int N = 500005;

int n, m, a[N];
i64 t1[N]; int t2[N]; ull t3[N];

int sm2(int x) {
	switch (x & 3) {
		case 0: return x;
		case 1: return 1;
		case 2: return x + 1;
		case 3: return 0;
	default: return -1;
	}
}

ull sm3(int p) {
	ull a = 1ll * p * (p + 1);
	ull b = p * 2 + 1;
	if (a % 2 == 0) { a /= 2; } else { b /= 2; }
	if (a % 3 == 0) { a /= 3; } else { b /= 3; }
	return a * b;
}

void modify(int x) {
	for (int p = x; p <= n; p += lowbit(p)) {
		t1[p] += a[x];
		t2[p] ^= a[x];
		t3[p] += 1ull * a[x] * a[x];
	}
}

int main(/*int argc, char const* argv[]*/) {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m;
	rep (i, 1, n) { std::cin >> a[i]; modify(i); }
	while (m--) {
		int op, l, r; std::cin >> op >> l >> r;
		if (op == 1) {
			for (int p = l; p <= n; p += lowbit(p)) {
				t1[p] += r - a[l];
				t2[p] ^= r ^ a[l];
				t3[p] += 1ull * r * r - 1ull * a[l] * a[l];
			}
			a[l] = r;
		} else {
			i64 h1 = 0; int h2 = 0; ull h3 = 0;
			int ll = l, rr = r;
			for (; ll <= rr; rr -= lowbit(rr)) {
				h1 += t1[rr]; h2 ^= t2[rr]; h3 += t3[rr];
			} ll--;
			for (; ll > rr; ll -= lowbit(ll)) {
				h1 -= t1[ll]; h2 ^= t2[ll]; h3 -= t3[ll];
			}
			int res = 0; h1 *= 2;
			if (h1 % (r - l + 1) == 0) {
				int fr = h1 / (r - l + 1) - (r - l);
				if (!(fr % 2)) { fr /= 2;
					if ((sm2(fr - 1) ^ sm2(fr + r - l)) == h2
						and sm3(fr + r - l) - sm3(fr - 1) == h3) {
						res = 1;
					}
				}
			}
			std::cout << (res ? "damushen" : "yuanxing") << '\n';
		}
	}
}