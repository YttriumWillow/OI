#include <iostream>

#pragma GCC target("avx","avx2","avx512f","sse","sse2","sse3","sse4.1","sse4.2")

#define gc() (iS == iT && (iT = (iS = buf) + fread(buf, 1, 1 << 17, stdin), iS == iT) ? EOF : *iS++)
char buf[1 << 18], *iS = buf, *iT = buf;

using namespace std;

static inline void read(int& x)
{
	static char c;
	while (!isdigit(c = gc()));
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
}

#define i64 long long
int n, a[50001], ans;

signed main()
{
	read(n), ans = n;
	for (int i = 1; i <= n; ++i) read(a[i]);
	int l = 1, r, d;
	while (l <= n)
	{
		int Max = *(a + l), Min = *(a + l);
		r = l + 1, d = r - l;
		while (r + 64 <= n)
		{
			Min = min(Min, a[r]), Max = max(Max, a[r]), (d == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 1]), Max = max(Max, a[r + 1]), (d + 1 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 2]), Max = max(Max, a[r + 2]), (d + 2 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 3]), Max = max(Max, a[r + 3]), (d + 3 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 4]), Max = max(Max, a[r + 4]), (d + 4 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 5]), Max = max(Max, a[r + 5]), (d + 5 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 6]), Max = max(Max, a[r + 6]), (d + 6 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 7]), Max = max(Max, a[r + 7]), (d + 7 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 8]), Max = max(Max, a[r + 8]), (d + 8 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 9]), Max = max(Max, a[r + 9]), (d + 9 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 10]), Max = max(Max, a[r + 10]), (d + 10 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 11]), Max = max(Max, a[r + 11]), (d + 11 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 12]), Max = max(Max, a[r + 12]), (d + 12 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 13]), Max = max(Max, a[r + 13]), (d + 13 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 14]), Max = max(Max, a[r + 14]), (d + 14 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 15]), Max = max(Max, a[r + 15]), (d + 15 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 16]), Max = max(Max, a[r + 16]), (d + 16 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 17]), Max = max(Max, a[r + 17]), (d + 17 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 18]), Max = max(Max, a[r + 18]), (d + 18 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 19]), Max = max(Max, a[r + 19]), (d + 19 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 20]), Max = max(Max, a[r + 20]), (d + 20 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 21]), Max = max(Max, a[r + 21]), (d + 21 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 22]), Max = max(Max, a[r + 22]), (d + 22 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 23]), Max = max(Max, a[r + 23]), (d + 23 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 24]), Max = max(Max, a[r + 24]), (d + 24 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 25]), Max = max(Max, a[r + 25]), (d + 25 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 26]), Max = max(Max, a[r + 26]), (d + 26 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 27]), Max = max(Max, a[r + 27]), (d + 27 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 28]), Max = max(Max, a[r + 28]), (d + 28 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 29]), Max = max(Max, a[r + 29]), (d + 29 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 30]), Max = max(Max, a[r + 30]), (d + 30 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 31]), Max = max(Max, a[r + 31]), (d + 31 == Max - Min) ? ++ans : 1,
			r += 32, d += 32;
			Min = min(Min, a[r]), Max = max(Max, a[r]), (d == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 1]), Max = max(Max, a[r + 1]), (d + 1 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 2]), Max = max(Max, a[r + 2]), (d + 2 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 3]), Max = max(Max, a[r + 3]), (d + 3 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 4]), Max = max(Max, a[r + 4]), (d + 4 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 5]), Max = max(Max, a[r + 5]), (d + 5 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 6]), Max = max(Max, a[r + 6]), (d + 6 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 7]), Max = max(Max, a[r + 7]), (d + 7 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 8]), Max = max(Max, a[r + 8]), (d + 8 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 9]), Max = max(Max, a[r + 9]), (d + 9 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 10]), Max = max(Max, a[r + 10]), (d + 10 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 11]), Max = max(Max, a[r + 11]), (d + 11 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 12]), Max = max(Max, a[r + 12]), (d + 12 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 13]), Max = max(Max, a[r + 13]), (d + 13 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 14]), Max = max(Max, a[r + 14]), (d + 14 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 15]), Max = max(Max, a[r + 15]), (d + 15 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 16]), Max = max(Max, a[r + 16]), (d + 16 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 17]), Max = max(Max, a[r + 17]), (d + 17 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 18]), Max = max(Max, a[r + 18]), (d + 18 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 19]), Max = max(Max, a[r + 19]), (d + 19 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 20]), Max = max(Max, a[r + 20]), (d + 20 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 21]), Max = max(Max, a[r + 21]), (d + 21 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 22]), Max = max(Max, a[r + 22]), (d + 22 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 23]), Max = max(Max, a[r + 23]), (d + 23 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 24]), Max = max(Max, a[r + 24]), (d + 24 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 25]), Max = max(Max, a[r + 25]), (d + 25 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 26]), Max = max(Max, a[r + 26]), (d + 26 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 27]), Max = max(Max, a[r + 27]), (d + 27 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 28]), Max = max(Max, a[r + 28]), (d + 28 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 29]), Max = max(Max, a[r + 29]), (d + 29 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 30]), Max = max(Max, a[r + 30]), (d + 30 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 31]), Max = max(Max, a[r + 31]), (d + 31 == Max - Min) ? ++ans : 1,
			r += 32, d += 32;
		}
		while (r + 8 <= n)
		{
			Min = min(Min, a[r]), Max = max(Max, a[r]), (d == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 1]), Max = max(Max, a[r + 1]), (d + 1 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 2]), Max = max(Max, a[r + 2]), (d + 2 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 3]), Max = max(Max, a[r + 3]), (d + 3 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 4]), Max = max(Max, a[r + 4]), (d + 4 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 5]), Max = max(Max, a[r + 5]), (d + 5 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 6]), Max = max(Max, a[r + 6]), (d + 6 == Max - Min) ? ++ans : 1,
			Min = min(Min, a[r + 7]), Max = max(Max, a[r + 7]), (d + 7 == Max - Min) ? ++ans : 1,
			r += 8, d += 8;
		}
		while (r <= n)
		{
			Min = min(Min, a[r]), Max = max(Max, a[r]), (r - l == Max - Min) ? ++ans : 1;
			++r;
		}
		++l;
	}
	cout << ans << endl;
	return 0;
}