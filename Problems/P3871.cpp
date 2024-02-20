#include <bits/stdc++.h>
#define qwq puts("fzy_qwq\n");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
vector<longint> a;
longint n, x, q;
string opr;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    cin >> q;
    while (q--)
    {
        cin >> opr;
        if (opr == "add")
        {
            scanf("%lld", &x);
            a.insert(lower_bound(a.begin(), a.end(), x), x);
        }
        else if (opr == "mid")
            printf("%lld\n",a[(a.size() - 1) / 2]);
    }
    return 0;
}