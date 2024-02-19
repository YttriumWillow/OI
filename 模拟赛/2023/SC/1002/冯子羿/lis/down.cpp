#include <iostream>
#include <cstdio>
#include <algorithm>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

const int N = 1e7 + 10;

using namespace std;

using std::min;
static inline int __my_rand(int *seed)
{
    *seed = *seed * 1103515245 + 12345;
    return ((unsigned) * seed) / 34;
}
int gen(int N, int Lim, int seed, int* F)
{
    int cur = 0;
    for (int i = 1; i <= N; i ++)
    {
        int rd = __my_rand(&seed);
        if (rd % std::min(10, cur + 1) == 0 && cur < Lim) F[i] = ++cur;
        else F[i] = (__my_rand(&seed) % cur) + 1;
    }
    return 0;
}

int n, lim, seed, f[N];

int main()
{
    scanf("%d%d%d", &n, &lim, &seed);
    gen(n, lim, seed, f);
    for (int i = 1; i <= n; ++i)
        cout << f[i] << " \n"[i == n];
    return 0;
}
