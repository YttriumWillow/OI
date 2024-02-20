#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;
const int LOG = 18;

int n, m;
int a[N], f[N];
int pre[N], suf[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
		
	for (int i = 1; i <= n; ++i)
		pre[i] = max(pre[i - 1], a[i]);
	for (int i = n; i >= 1; --i)
		suf[i] = max(suf[i + 1], a[i]);
		
	for (int i = 1; i <= n; ++i)
		for (int j = 0; i - j * j - 1 >= 1; ++j)
			f[i] = max(f[i], pre[i - j * j - 1] + j + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; i + j * j + 1 <= n; ++j)
			f[i] = max(f[i], suf[i + j * j + 1] + j + 1);
	
	for (int i = 1; i <= n; ++i)
		cout << max(f[i] - a[i], 0) << endl;
	return 0;
}