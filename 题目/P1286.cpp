#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, a[N], sum;

inline void solve(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	sum /= 2;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n && n) solve(n);
	return 0;
}