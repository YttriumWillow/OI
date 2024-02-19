#include <bits/stdc++.h>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~	");

using namespace std;

int main()
{
	int n; cin >> n;
	if (!(n & 1))
	{
		cout << 1 << endl;
		for (int i = 1; i <= n / 2; ++i)
			cout << 1;
		for (int i = 1; i <= n / 2; ++i)
			cout << 0;
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}