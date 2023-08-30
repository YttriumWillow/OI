#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, res;

int main()
{
	cin >> n;
	for (i64 i = 1; i * i <= n - 1; ++i)
	{
		i64 p = n - 1;
		if (!(p % i))
			res += (i * i != p) + (i != 1);
	}
	for (i64 i = 2; i * i <= n; ++i)
	{
		i64 p = n;
		while (!(p % i)) p /= i;
		res += (p != n && p % i == 1);
	}
	cout << res + 1 << endl;
	return 0;
}