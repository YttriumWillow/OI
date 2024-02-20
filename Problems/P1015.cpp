#include <iostream>

#include <algorithm>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

char tb[20] = "0123456789ABCDEF";
int n;
string m;
bool check(string a)
{
    string s = a;
    reverse(s.begin(), s.end());
    return s == a;
}
string add(int k, string b)
{
    string a = b;
    reverse(a.begin(), a.end());
    int xa[110], xb[110], xc[110];
    int len = a.length(), lenc = 1;
    string ans;
    for (int i = 0; i < len; i++)
    {
        if (isdigit(a[i]))  xa[len - i] = a[i] - '0';
        else                xa[len - i] = a[i] - 'A' + 10;
        if (isdigit(b[i]))  xb[len - i] = b[i] - '0';
        else                xb[len - i] = b[i] - 'A' + 10;
    }
    int x = 0;
    while (lenc <= len)
    {
        xc[lenc] = xa[lenc] + xb[lenc] + x;
        x = xc[lenc] / k;
        xc[lenc] %= k;
        lenc++;
    }
    xc[lenc] = x;
    while (xc[lenc] == 0)
        lenc--;
    for (int i = lenc; i >= 1; i--)
        ans += tb[xc[i]];
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i <= 30; i++)
    {
        if (check(m))
        {
            printf("STEP=%d", i);
            return 0;
        }
        else m = add(n, m);
    }
    printf("Impossible!");
    return 0;
}
