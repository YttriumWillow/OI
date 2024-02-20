#include <iostream>
#include <ctime>
#include <random>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

int main()
{
	freopen("D.in", "w", stdout);
	srand(time(0));

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	const int n = 30000;
	cout << n << endl;
	for (int i = 1; i <= n; ++i)
		cout << rand() << endl;
	return 0;
}