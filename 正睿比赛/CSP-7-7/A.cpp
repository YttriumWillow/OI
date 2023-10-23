#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, res;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	while (n)
	{
		res += n % 60;
		n /= 60;
	}

	cout << res << endl;
	return 0;
}