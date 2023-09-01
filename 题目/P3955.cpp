#include <iostream>

#include <cmath>
#include <algorithm>

#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, q, l, x, mod;
vector<int> isbn(1010);

inline void fzyqwq()
{
    for (auto awa : isbn)
        if (awa % mod == x)
        {
            cout << awa << endl;
            return;
        }
    cout << -1 << endl;
    return;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &isbn[i]);
    sort(isbn.begin(), isbn.end());

    while (q--)
    {
        cin >> l >> x;
        mod = pow(10, l);
        fzyqwq();
    }
    return 0;
}