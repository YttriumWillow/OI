#include <iostream>
using namespace std;
#define int long long
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int n, a, b, opt, x = 0, y = 1;
inline void add()
{
    int g = y * b, h = x * b + y * a;
    int tmp = gcd(g, h);
    y = g / tmp, x = h / tmp;
}
inline void sub()
{
    int g = y * b, h = x * b - y * a;
    int tmp = gcd(g, h);
    y = g / tmp, x = h / tmp;
}
signed main()
{
    cin >> n;
    while (n--)
    {
        cin >> a >> b >> opt;
        switch (opt)
        {
        case 1:
            add();break;
        case 2:
            sub();break;
        }
    }
    if (y < 0) cout << x / -1 << '/' << y / -1 << endl;
    else if (x % y) cout << x << '/' << y << endl;
    else cout << x / y << endl;
    return 0;
}