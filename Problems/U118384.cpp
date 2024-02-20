#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;
const longint mod = 998244353;

longint n, k;

longint fpow(longint a, longint b)
{
    // a ^ b
    longint t = 1, y = a;
    while (b)
    {
        if (b & 1)
            t = t * y % mod;
        y = y * y % mod;
        b >>= 1;
    }
    return t % mod;
}


int main()
{
    cin >> n >> k;
    cout << fpow(fpow(2, k) - 1, n);
    return 0;
}

//  3 ^ 2 = 9
// 31 ^ 4 = 952351

// ans = (2 ^ k - 1) ^ n