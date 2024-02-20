#include <iostream>
#include <bitset>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

int n, tot[100];
char res[100][10000];

bitset<10000010> isprime;
// bitset 优化埃氏筛
inline void Eratosthenes(int n)
{
    isprime.set(); isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (isprime[i])
            for (int j = i << 1; j <= n; j += i)
                if (isprime[j] == 1)
                    isprime[j] = 0;
}

inline char nxt(char x)
{
	if (x == 'Z') return 'A';
	else return x + 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; Eratosthenes(100000);

	rep (i, 1, n)
	{
		int j = 1, cnt = 0;
		char cur = 'A' + i - 1;

		while (cnt < i * i)
		{
			if (!isprime[j + cur]) res[i][j] = ' ';
			else res[i][j] = cur, cur = nxt(cur), ++cnt;
			++j;
		}
		tot[i] = j;
	}

	rep (i, 1 ,n)
	{
		rep (j, 1, tot[i] - 1)
		{
			cout << res[i][j];
		}	
		cout << res[i][tot[i]] << endl;	
	}


	return 0;
}