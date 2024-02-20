#include <bits/stdc++.h>
#define longint long long
#define reg register
using namespace std;
string x, str;
longint charmax;
longint ans[26];
int main()
{
    while(cin >> x)
        str += x;
    longint n = str.size();
    for (int i = 0; i < n; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            ans[str[i] - 'A']++;
    for (int i = 0; i < 26; i++)
        charmax = max(charmax, ans[i]);
    for(int i = charmax; i > 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (ans[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++)
        printf("%c ", 'A' + i);
    return 0;
}
