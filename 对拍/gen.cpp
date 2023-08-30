#include <bits/stdc++.h>

#define i64 long long
#define all(x) x.begin(), x.end()
#define seg(a, l, r) a + l, a + r + 1
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count()); 

i64 rnd(i64 l, i64 r) {
	return mt_rand() % (r - l + 1) + l;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int n, m, q, V, u, v;
	n = rnd(3, 1e5);
	m = rnd(1, 5e5);
	q = rnd(1, 5e5);
	V = rnd(0, (1ll << 60) - 1);
	u = 0, v = 0;
	cout << n << ' ' << m << ' ' << q << ' ' << V << endl;

	for (int i = 1; i <= m; ++i)
	{
		while (u == v) tie(u, v) = make_pair(rnd(1, n), rnd(1, n));
		cout << u << ' ' << v << ' ' << rnd(0, (1ll << 60) - 1) << endl;
	}
	for (int i = 1; i <= q; ++i)
	{
		while (u == v) tie(u, v) = make_pair(rnd(1, n), rnd(1, n));
		cout << u << ' ' << v << endl;
	}

    return 0;
}
