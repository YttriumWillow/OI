#include <iostream>

#include <bitset>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'

using namespace std;

longint a[7], ans;
longint w[7] = { 0, 1, 2, 3, 5, 10, 20 };
bitset<1145> f;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    f[0] = 1;
    for (reg int i = 1; i <= 6; i++)
        cin >> a[i];
    cout << endl;
    for (reg int i = 1; i <= 6; i++)
        for (reg int j = 1; j <= a[i]; j++)
            for (reg int k = 1000; k >= 0; k--)
                if (f[k]) f[k + w[i]] = 1;
    for (reg int k = 1000; k > 0; k--)
        if (f[k]) ans++;
    cout << "Total=" << ans << endl;
    return 0;
}