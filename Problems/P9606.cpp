#include <iostream>

#include <cstring>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int base = 53;

int zip(char x)
{
    if ('a' <= x && x <= 'z')   return x - 'a';
    else                        return x - 'A' + 26;
}

int n, pos;
u64 now = 1;
u64 pre[400010];
u64 suf[400010];
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> str;
    pos = 0;
    pre[n + 1] = suf[n + 1] = 0; now = 1;

    for (reg int i = n; i >= 1; --i)
    {
        pre[i] = pre[i + 1] * base + (str[i - 1] - 'a');
        suf[i] = suf[i + 1] + (str[i - 1] - 'a') * now;
        now *= base;
    }
    for (reg int i = n; i >= 1; --i)
        if (pre[i] == suf[i])
            pos = i - 1;
    cout << pos << endl;
    return 0;
}