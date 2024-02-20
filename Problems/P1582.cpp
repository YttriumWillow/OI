#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint lowbit(longint x)
{
    return x & -x;
}
longint n, k, ans;
int main()
{
    cin >> n >> k;
    while (__builtin_popcount(n) > k)
    {
        ans += lowbit(n);
        n += lowbit(n);
    }
    cout << ans << endl;
    return 0;
}