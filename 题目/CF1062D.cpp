#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, ans;

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
        for (int j = i * 2; j <= n; j += i)
            ans += j / i;
    cout << ans * 4 << endl;
    return 0;
}