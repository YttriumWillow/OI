#include <iostream>

#define i64 long long
#define qwq puts("fzy qwq ~")

using namespace std;

int n; i64 cnt[2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1, x; i <= n; ++i)
	{
		cin >> x;
		cnt[!(i % 2)] += x / 2;
		cnt[(i % 2)] += x / 2 + (x % 2);
	}
	cout << min(cnt[0], cnt[1]) << endl;
	return 0;
}
