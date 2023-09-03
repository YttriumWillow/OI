// Problem:       P2043 质因子分解
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P2043
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-21 14:17:13 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e4 + 10;

int n, cnt[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 2; i <= n; ++i)
	{
		for (int t = i, j = 2; j <= i; ++j)
			while (!(t % j))
				++cnt[j], t /= j;
	}
	for (int i = 2; i <= 10000; ++i)
		if (cnt[i])
			cout << i << ' ' << cnt[i] << endl;
	return 0;
}