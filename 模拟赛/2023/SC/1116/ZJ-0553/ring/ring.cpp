#include <iostream>
#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 2e6 + 10;

int n, m, res = N;
struct Seg
{
	int l, r;
	friend bool operator < (const Seg& A, const Seg& B) { return A.l ^ B.l ? A.l < B.l : A.r < B.r; }
} S[N];

int tot;

int main()
{
	file("ring");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	rep (i, 1, m)
	{
		int l, r; cin >> l >> r; if (l > r) r += n;
		S[++tot] = { l, r };
		S[++tot] = { l + n, r + n };
	}

	sort(S + 1, S + tot + 1);

	rep (i, 1, m)
	{
		int j = i + 1, l = S[i].l, r = S[i].r, cnt = 1;
		for (int MaxR = 0; j < i + m and r < l + n - 1;)
		{
			for (; j < i + m and S[j].l <= r + 1; ++j) MaxR = max(MaxR, S[j].r);
			r = MaxR; ++cnt;
			if (S[j].l > r + 1) break;
		}
		if (r >= l + n - 1) res = min(res, cnt);
		if ((double)clock() / CLOCKS_PER_SEC > 2.5) break;
	}

	cout << res << endl;


	return 0;
}