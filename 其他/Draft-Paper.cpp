#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

inline void val(int x)
{
	cerr << x % 2023 << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cout << n + m << endl;
	val(n + m);
	return 0;
}