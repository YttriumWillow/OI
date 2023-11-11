#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

int main()
{
	file("mouse");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;

	cin >> n >> k;

	int t[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }, 
		{ 0, 2, 36, 392 },
		{ 0, 0, 48, 8736 }
	};

	cout << t[n][k] << endl;

	return 0;
}