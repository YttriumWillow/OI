#include <bits/stdc++.h>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1000000007;
const int inv100 = 570000004;
longint n, a, b, ans, x, y, down;
longint p[5000010];
longint q[5000010];

inline void exgcd(longint a, longint b, longint& x, longint& y)
{
    if (b == 0) { x = 1; y = 0; return; }
    exgcd(b, a % b, x, y);
    longint tmp = x;
    x = y;
    y = tmp - (a / b) * y;
}
inline longint inv(longint a)
{
    exgcd(a, mod, x, y);
    return (mod + x % mod) % mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;  p[0] = 1;
    for (reg int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        a = a * inv100 % mod, b = b * inv100 % mod;
        down = inv( (1 - q[i - 1] * b % mod + mod) % mod );         // inv(1 - q * b)
        // p[i] 表示光线从第 1 面射到第 i 面余下光线按规求逆元
        // q[i] 表示光线穿过第 i 面余下光线按规求逆元
        q[i] = (b + a * a % mod * q[i - 1] % mod * down) % mod;     // b + a * a * q * down
        p[i] = p[i - 1] * a % mod * down % mod;                     // p * a * down
    }
    cout << p[n] << endl;
    return 0;
}