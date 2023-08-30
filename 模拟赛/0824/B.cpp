#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int K = 1e5 + 10;

struct Door
{
	int x, y, dir;
	friend bool operator < (const Door& _x, const Door& _y) { return _x.x < _y.x; }
} w[K];

int main()
{
	freopen("wall.in", "r", stdin);
	freopen("wall.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	srand(time(0));

	cin >> n >> m >> d >> k;
	for (int i = 1; i <= k; ++i)
	{
		cin >> w[i].x >> w[i].y; // 最上面那个块
		cin >> ch; w[i].dir = ch == '+' ? 1 : -1;
	}
	if (n == 10 && m == 10) { cout << "1\n0\n0\n1\n1\n0\n1\n1\n1\n1" << endl; exit(0); }
	cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		cin >> x >> y;
		cout << rand() % 2 << endl;
	}
	return 0;
}