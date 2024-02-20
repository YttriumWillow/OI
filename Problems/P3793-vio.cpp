#include <iostream>
#include <algorithm>

#define i64 long long 
#define ull unsigned long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

namespace GenHelper { unsigned z1, z2, z3, z4, b; unsigned rand_() { b = ((z1 << 6) ^ z1) >> 13; z1 = ((z1 & 4294967294U) << 18) ^ b; b = ((z2 << 2) ^ z2) >> 27; z2 = ((z2 & 4294967288U) << 2) ^ b; b = ((z3 << 13) ^ z3) >> 21; z3 = ((z3 & 4294967280U) << 7) ^ b; b = ((z4 << 3) ^ z4) >> 12; z4 = ((z4 & 4294967168U) << 13) ^ b; return (z1 ^ z2 ^ z3 ^ z4); } } void srand(unsigned x) { using namespace GenHelper; z1 = x; z2 = (~x) ^ 0x233333333U; z3 = x ^ 0x1234598766U; z4 = (~x) + 51; } int read() { using namespace GenHelper; int a = rand_() & 32767; int b = rand_() & 32767; return (a << 15) | b; }

const int N = 2e7 + 10;

struct Node
{
	int v, id; Node(){}
	friend bool operator < (const Node& A, const Node& B) { return A.v > B.v; }
} a[20000005];

inline int query(int l, int r)
{
	int p = 0; while (a[p].id < l || a[p].id > r) ++p;
	return a[p].v;
}

int n, m, s, l, r; ull res;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> s;

	srand(s);

	rep (i, 1, n)
		a[i].v = read(), a[i].id = i;

	sort(a + 1, a + n + 1);

	while (m--)
	{
		l = read() % n + 1;
		r = read() % n + 1;
		if (l > r) swap(l, r);
		res += query(l, r);
	}

	cout << res << endl;

	return 0;
}