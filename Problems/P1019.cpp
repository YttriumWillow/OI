#include<bits/stdc++.h>
using namespace std;
string str[21], start;
int used[21], ans = 0, n;
int check(string str1, string str2)
{
    int len1 = str1.size();
    int len = min(str1.size(), str2.size());
    for (int i = 1; i < len; i++)
    {
        int flag = 1;
        for (int j = 0; j < i; j++)
            if (str1[len1 - i + j] != str2[j])
                flag = 0;
        if (flag)
            return i;
    }
    return 0;
}
void dfs(string strnow, int lennow)
{
    ans = max(lennow, ans);
    for (int i = 1; i <= n; i++)
    {
        if (used[i] >= 2)
            continue;
        int c = check(strnow, str[i]);
        if (c > 0)
        {
            used[i]++;
            dfs(str[i], lennow + str[i].size() - c);
            used[i]--;
        }
    }
}
main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        used[i] = 0;
    }
    cin >> start;
    dfs(' ' + start, 1);
    cout << ans << endl;
    return 0;
}