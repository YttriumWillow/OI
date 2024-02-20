#include <bits/stdc++.h>
using namespace std;
int a[500014], b[500014], n;
int ans1, ans2 = 1, tmp;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if (tmp != a[i])
            ans1++;
        if (tmp != a[n - i + 1])
            ans2++;
    }
    printf("%d\n", min(ans1, ans2));
    return 0;
}