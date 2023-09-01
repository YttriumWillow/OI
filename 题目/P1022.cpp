#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint k, b, now, flag = 1, l = 1;
char ch, ans; bool isnum = true, start = true;
int main()
{
    while (scanf("%c", &ch) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            if (start)
                k += 1;
            k += flag * now * l;
            ans = ch;
            now = 0;
        }
        if (ch >= '0' && ch <= '9')
        {
            start = false;
            now = now * 10 + (ch - '0');
        }
        if (ch == '+')
        {
            b += now * flag * l;
            flag = 1;
            now = 0;
        }
        if (ch == '-')
        {
            b += now * flag * l;
            flag = -1;
            now = 0;
        }
        if (ch == '=')
        {
            b += now * flag * l;
            flag = 1;
            now = 0;
            l = -1;
        }
    }
    b += now * flag * l;
    if (ans == -0.0)
        ans = 0;
    printf("%c=%.3lf\n", ans, -b * 1.0 / k);
    return 0;
}