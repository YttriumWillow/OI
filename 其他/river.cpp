int len, m, L, R;
string s;
int a[maxn], cnt, f[20][20][20], nxt[maxn];
int dfs(int n, int p, int sum, bool f1, int f2)
{
	if (n == 0) { return sum; }
	if (!f1 && !f2 && f[n][p][sum] != -1) return f[n][p][sum];

	int m = (f1 ? a[n] : 9), res = 0;

	for (int i = 0; i <= m; i++)
	{
		int c1 = p, c2 = sum;
		if (!f2 || i != 0)
		{
			while (c1 && s[c1 + 1] - '0' != i) c1 = nxt[c1];
			if (s[c1 + 1] - '0' == i) c1++;
			if (c1 == len) c2++, c1 = nxt[c1];
		}
		res += dfs(n - 1, c1, c2, f1 && i == m, f2 && i == 0);
	}
	if (!f1 && !f2)
		return f[n][p][sum] = res; 
	return res;
}
int calc(int x)
{
	cnt = 0;
	while (x)
	{
		a[++cnt] = x % 10;
		x /= 10;
	}
	return dfs(cnt, 0, 0, 1, 1);
}
void solve()
{
	memset(f, -1, sizeof(f));
	cin >> s >> L >> R;
	len = sz(s); s = " " + s;
	rep_(i, 0, len) nxt[i] = 0;
	for (int i = 2, j = 0; i <= len; i++)
	{
		while (j && s[j + 1] != s[i]) j = nxt[j];
		if (s[j + 1] == s[i]) j++;
		nxt[i] = j;
	}
	cout << calc(R) - calc(L - 1) << endl;
}
