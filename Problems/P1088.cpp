#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;
int a[114514];

int main()
{
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    while (m--)
        next_permutation(a + 1, a + n + 1);
    for (reg int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    return 0;
}