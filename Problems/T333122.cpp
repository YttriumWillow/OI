// Problem:       T333122 你说得对
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/T333122
// Memory Limit:   MB
// Time Limit:     ms
// Created Time:  2023-05-01 08:07:12 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, k, ans;
int a[100010], b[100010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], ans += a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for (reg int i = 1; i <= m; ++i)
		cin >> b[i], ans += b[i];
	int lmt = min(n, m);
	for (reg int i = 1; i <= lmt; ++i)
		ans += max(a[i], k);
	cout << ans << endl;
	return 0;
}