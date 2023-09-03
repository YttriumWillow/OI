#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
using namespace std;
/* 用 python 找出来的可爱小规律qwq

C:\Users\LEGION> python
Python 3.10.6 (tags/v3.10.6:9c7b4bd, Aug  1 2022, 21:53:49) [MSC v.1932 64 bit (AMD64)] on win32
Type "help", "copyright", "credits" or "license" for more information.
0.8871595330739328
>>> 0.0077821011673152 * 514 # 样例2
4.000000000000013
>>> 0.0051987767584098 * 9810 # 样例3
51.000000000000135
>>> 514 // 114 # 样例2
4
>>> 9810 // 191 # 样例3
51

*/
longint a, b;
int main()
{
    cin >> a >> b;
    cout << fixed << setprecision(16) << (b / a) / 1.0 / b;
    return 0;
}