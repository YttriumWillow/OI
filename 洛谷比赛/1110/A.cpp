#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 a, b, R, V, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> R >> V >> M;
	cout << R * (2 * 2 * a + b)  << ' ' << V * (2 * 3 * a + b) << ' ' << M * (2 * 3 * a + b) << endl;
	return 0;
}