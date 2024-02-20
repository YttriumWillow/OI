#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
longint n, m, T, tmp;
longint a[6], b[6];
bool    p[6];
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
void print()
{
    for (int i = 1; i <= 5; i++)
        cout << b[i] << ' ';
    cout << endl;
}
int main()
{
    T _read;
    while (T--)
    {
        bool shunzi, duizi;
        for (int i = 1; i <= 4; i++)
            a[i] _read;
        for (int i = 0; i <= 9; i++)
        {
            // 4 2 7 9
            a[5] = i;
            shunzi = duizi = false;
            memcpy(b, a, sizeof(b));
            sort(b + 1, b + 6);
            // print();// warning
            for (int i = 1; i < 5; i++)
                if (b[i] == b[i + 1])
                {
                    duizi = true;
                    swap(b[i], b[5]);
                    swap(b[i + 1], b[4]);
                }
            sort(b + 1, b + 4);
            if (b[1] == b[2] - 1 && b[3] == b[2] + 1)
                shunzi = true;

            // print();// warning
            if (duizi && shunzi)
            {
                printf("%d\n", 1);
                break;
            }
        }
        if (!(duizi && shunzi))
            printf("%d\n", 0);
    }
    return 0;
}