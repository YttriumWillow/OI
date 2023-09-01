#include <bits/stdc++.h>
#define qwq puts("fzy qwq~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
const longint mod = 1000000007L;
struct Matrix
{   // 并非普通矩阵，是二阶方阵qwq
    longint a[3][3];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix operator*(const Matrix& b) const
    {
        Matrix res;
        for (longint i = 1; i <= 2; ++i)
            for (longint j = 1; j <= 2; ++j)
                for (longint k = 1; k <= 2; ++k)
                    res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % mod;
        return res;
    }
} ans, base;
longint n;
void init()
{   // 初始化 ans、base 矩阵qwq
    base.a[1][1] = 1; base.a[1][2] = 1;
    base.a[2][1] = 1;
    ans.a[1][1] = 1; ans.a[1][2] = 1;
}
void qpow(longint b)
{   // 求矩阵快速幂qwq
    while (b)
    {
        if (b & 1)
            ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}

int main()
{
    scanf("%lld", &n);
    if (n <= 2)
    {
        printf("%d\n", 1);
        return 0;
    }
    init();
    qpow(n - 2);
    printf("%lld\n", ans.a[1][1] % mod);
    return 0;
}