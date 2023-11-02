#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int n, m;

int main()
{
	file("together");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	cout << n * (n - 1) << endl;
	return 0;
}