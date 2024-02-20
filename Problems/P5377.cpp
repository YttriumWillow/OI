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

	while (cin >> n) cout << (n * n * n * n - 6 * n * n * n + 23 * n * n - 18 * n) / 24 + 1 << endl;
	return 0;
}