#include <bits/stdc++.h>
#define qwq puts("fzy_qwq");
#define reg register
#define _read =read()
using namespace std;
int n, q, T, idx;
int trie[3000010][63];
int cnt[3000010];
string str;
void clear()
{
    for (int i = 0; i <= idx; i++)
        for (int j = 0; j <= 62; j++)
            trie[i][j] = 0;
    for (int i = 0; i <= idx; i++)
        cnt[i] = 0;
    idx = 0;
}
int zip(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 26;
    else if (c >= '0' && c <= '9')
        return c - '0' + 52;
    return -1;
}
void insert(string str)
{
    int len = str.size();
    int now = 0;
    for (int i = 0; i < len; i++)
    {
        int x = zip(str[i]);
        if (!trie[now][x])
            trie[now][x] = ++idx;
        now = trie[now][x];
        cnt[now]++;
    }
}
int query(string str)
{
    int len = str.size();
    int now = 0;
    for (int i = 0; i < len; i++)
    {
        int x = zip(str[i]);
        if (!trie[now][x])
            return 0;
        now = trie[now][x];
    }
    return cnt[now];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--)
    {
        clear();
        cin >> n >> q; idx = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            insert(str);
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> str;
            cout << query(str) << endl;
        }
    }
    return 0;
}