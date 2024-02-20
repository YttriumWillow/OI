// Problem:       P4170 [CQOI2007] 涂色
// Contest:       Luogu
// URL:           https://www.luogu.com.cn/problem/P4170
// Memory Limit:  125 MB
// Time Limit:    1000 ms
// Created Time:  2023-07-23 20:16:42

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 510;
const int inf = 0x3f3f3f3f;

int n;
string s;
int f[N][N];

int main()
{
    cin >> s; n = s.size();
    
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= n; ++j)
    		f[i][j] = (i == j) ? 1 : inf;
    
    for (int l = 1; l < n; ++l)
        for (int i = 1, j = 1 + l; j <= n; ++i, ++j)
        {
            if (s[i - 1] == s[j - 1])
                f[i][j] = min(f[i + 1][j], f[i][j - 1]);
            else
            {
                for (int k = i; k < j; ++k)
                    f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
        }
    cout << f[1][n] << endl;
    return 0;
}
