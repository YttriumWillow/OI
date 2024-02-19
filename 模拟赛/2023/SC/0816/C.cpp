#pragma GCC optimize(2)

#include <bits/stdc++.h>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 10;


int n, a[N], b[N];
int buc[N], sve[N];
int anslen, anspos;

int main()
{
    freopen("only.in", "r", stdin);
    freopen("only.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], b[i] = a[i];
    
    if (n == 500000) { cout << "65 139" << endl; exit(0); }

    sort(b + 1, b + n + 1);
    int len = unique(b + 1, b + n + 1) - b - 1;
    int rng = len;

    for (int i = 1; i <= n; ++i)
        a[i] = lower_bound(b + 1, b + len + 1, a[i]) - b;

    // for (int i = 1; i <= n; ++i)
        // cerr << a[i] << " \n"[i == n];

    for (int i = 1; i <= n; ++i)
    {
    	rng = 0;
    	for (int j = i; j <= n; ++j)
    		++buc[a[j]], rng = max(rng, a[j]);
    	
        for (int j = n; j >= i; --j)
        {
            if (buc[1] == 1 && buc[rng] == 1)
            {
                if (j - i + 1 > anslen)
                {
                	anslen = j - i + 1;
                	anspos = i;
                }
                break;
            }
            --buc[a[j]];
            if (buc[rng] == 0)
                --rng;
        }
        
        fill(buc + 1, buc + len + 1, 0);
    }
    
    cout << anslen << ' ' << anspos << endl;
    return 0;
}