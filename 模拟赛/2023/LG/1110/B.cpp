#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 a, b, c, d, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c >> d >> M;

	i64 simple = 5 * c;
	i64 up = 20;

	if (simple <= M) up = 0;

	cout << max(0ll, simple + d * up - (b - d) * 20) << endl;

	return 0;
}