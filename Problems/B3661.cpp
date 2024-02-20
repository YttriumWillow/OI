#include<bits/stdc++.h>
using namespace std;
int a[10010], b[10010], c[10010];
int main()
{
    stack<int> st;
    int n, cntb = 0, cntc = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // cntb, cntc初值为0
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 1)
            b[++cntb] = a[i];
        else
            c[++cntc] = a[i];
    }
    for (int i = 1; i <= cntb; i++)
        cout << b[i] << " ";
    cout << endl;
    for (int i = 1; i <= cntc; i++)
        cout << c[i] << " ";
    cout << endl;
    return 0;
}
