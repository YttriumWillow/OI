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
    
	int n, m;
	n = rnd(3, 1e5);
	m = rnd(1, 1e5);
	cout << n << ' ' << m << endl;

	for (int i = 1; i <= n; ++i)
	{
		cout << rnd(1, 1e9) << endl;
	}
	for (int i = 1; i <= m; ++i)
	{
		int l = rnd(1, n);
		cout << l << ' ' << l + rnd(1, n - l - 1) << endl;
	}

    return 0;
}
