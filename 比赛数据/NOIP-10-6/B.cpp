#include<bits/stdc++.h>
#define ll long long
#define pre(i,a,b) for(int i=a;i<=b;++i)
#define suf(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N = 5e3 + 5;
namespace Y
{
ll n, k, A, B;
i64 t[N];
array<array<ll, N>, N> f;
void MAIN()
{
	// freopen("songfen.in", "r", stdin);
	// freopen("songfen.out", "w", stdout);
	cin >> n >> k >> A >> B;
	pre(i, 1, n) cin >> t[i];
	pre(i, 0, n) pre(j, 1, n + 1) f[i][j] = 3e15;
	f[0][1] = 0;
	pre(i, 1, n)
	{
		pre(j, max(i - k + 1, 1ll), n)
		{
			f[i][min(j + k, n + 1)] = min(f[i][min(j + k, n + 1)], f[i - 1][j] + A);
			if (j <= i) f[i][j + 1] = min(f[i][j + 1], f[i - 1][j] + t[i] + (B * (i - j)));
			if (i - j + 1 < k) f[i][j] = min(f[i][j], f[i - 1][j]);
		}
		// cout<<"# "<<f[i][i+1]<<endl;
	}
	cout << f[n][n + 1] << endl;
};
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1;
	while (T--) Y::MAIN();
	return 0;
}