#include <iostream>
#include <cstring>
#include <queue>

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)

using namespace std;

const int N = 3e4 + 10, M = 1e4 + 10;


struct tree
{
	int son[26];
	bool leaf;
} tr[260010];
string s[N]; 
int cnt, ans, n, din[26];
bool st[N];
int h[26], e[M], ne[M], idx;

inline void add(int a, int b)
{
	ne[idx] = h[a], e[idx] = b, h[a] = idx++;
}

inline void insert(string& str)
{
	int now = 0;
	int len = str.size() - 1;
	rep(i, 0, len)
	{
		if (!tr[now].son[str[i] - 'a']) tr[now].son[str[i] - 'a'] = ++cnt;
		now = tr[now].son[str[i] - 'a'];
	}

	tr[now].leaf = true;
}

inline void topsort()
{
	queue<int> q;
	for (int i = 0; i < 26; ++i) if (!din[i]) q.push(i);

	while (q.size())
	{
		int t = q.front();
		q.pop();

		for (int i = h[t]; ~i; i = ne[i])
		{
			int j = e[i];
			if (!(--din[j])) q.push(j);
		}
	}
}

inline bool find(string& str)
{
	memset(din, 0, sizeof din);
	memset(h, -1, sizeof h);
	idx = 0;

	int len = str.size() - 1;
	int now = 0;
	rep(i, 0, len)
	{
		if (tr[now].leaf) return 0;

		int k = str[i] - 'a';
		rep(j, 0, 25)
		{
			if (j == k) continue;
			if (tr[now].son[j])
			{
				add(k, j), din[j]++;
			}
		}

		now = tr[now].son[str[i] - 'a'];
	}

	topsort();

	rep(i, 0, 25) if (din[i]) return 0;

	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	rep(i, 1, n)
	{
		cin >> s[i];
		insert(s[i]);
	}

	rep(i, 1, n)
	{
		if (find(s[i]))
		{
			ans++;
			st[i] = true;
		}
	}

	cout << ans << '\n';
	rep(i, 1, n) if (st[i]) cout << s[i] << '\n';
}