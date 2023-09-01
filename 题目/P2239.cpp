#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, i, j, mi, ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> i >> j;
    mi = min(i, min(j, min(n - i + 1, n - j + 1)));
    if (i <= j)
        ans = mi * (4 * (n - 1) - 4 * mi) + 10 * mi - 4 * n - 3 + i + j;
    else
        ans = mi * (4 * n - 4 * mi) + 2 * mi + 1 - i - j;
    cout << ans << endl;
    return 0;
}
