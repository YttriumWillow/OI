#include <iostream>

#define i64 long long
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)

using namespace std;

const int N = 2e5 + 10;

ull n, k, x, res;
ull a[N], prv[N], suf[N];

inline ull fpow(ull a, int k)
{
	ull res = 1;
	for (; k; k >>= 1)
	{
		if (k & 1) res = res * a;
		a = a * a;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k >> x;
	rep (i, 1, n) cin >> a[i];

	rep (i, 1, n) prv[i] = prv[i - 1] | a[i];
	per (i, n, 1) suf[i] = suf[i + 1] | a[i];

	rep (i, 1, n) res = max(res, prv[i - 1] | (a[i] * fpow(x, k)) | suf[i + 1]);

	cout << res << endl;
	return 0;
}