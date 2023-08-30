#include <iostream>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 3;

int n, k, l[N], r[N];
int v[N << 1], sum, ans, cnt;
int w[N << 1], c[N << 1];
int d[N << 1];

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> l[i] >> r[i];
		v[++cnt] = l[i];
		v[++cnt] = r[i];
	}
	sort(v + 1, v + 1 + cnt);
	for (int i = 1; i <= n; ++i)
	{
		++w[ (l[i] = lower_bound(v + 1, v + 1 + cnt, l[i]) - v) + 1]; // ++w[a + 1];
		--w[ (r[i] = lower_bound(v + 1, v + 1 + cnt, r[i]) - v) + 1]; // --w[b + 1];
	}
	for (int i = 1; i <= cnt; ++i)
	{
		w[i] += w[i - 1]; int l = v[i] - v[i - 1];
		c[i] = c[i - 1] + (w[i] == 1) * l, sum = sum + (w[i] >= 1) * l;
	}

	// 这下面还要考虑多条去掉线段贡献的容斥
	// 原题是去掉一条线段

	for (int i = 1; i <= n; ++i)
		d[i] = c[r[i]] - c[l[i]];

	sort(d + 1, d + n + 1);

	for (int i = 1; i <= k; ++i)
		ans -= d[i];
	
	cout << ans << endl;
	return 0;
}
// 