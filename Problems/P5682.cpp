#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
int a[200010];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1, greater<int>());
    n = unique(a + 1, a + n + 1) - a - 1;
    if (n <= 1)
        printf("-1\n");
    else
        printf("%d\n", max(a[3], a[1] % a[2]));
    return 0;
}