#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint date1, date2, tmp, ans;
longint month[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main()
{
    cin >> date1 >> date2;
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= month[i]; j++)
        {
            tmp = ( (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10) ) * 10000 + i * 100 + j;
            if (tmp < date1 || tmp > date2) continue;
            ans++;
        }
    cout << ans << endl;
    return 0;
}
