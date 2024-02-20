#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
using namespace std;
longint t, ans;  // 习惯性开 long long
longint cnt[26];
// 只有 26 个小写字母，省点空间用来本地跑别的题的暴力^-^
char ch1, ch2, ch3, ch4;
int main()
{
    cin >> t;
    while (t--) // 多组数据读入 std 写法
    {
        memset(cnt, 0, sizeof(cnt));
        ans = 0;

        cin >> ch1 >> ch2;
        cin >> ch3 >> ch4;
        // 比较负责任的变量名
        cnt[ch1 - 'a']++;
        cnt[ch2 - 'a']++;
        cnt[ch3 - 'a']++;
        cnt[ch4 - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt[i] != 0)
                ans++;
        cout << ans - 1 << endl;
    }
    return 0;
}