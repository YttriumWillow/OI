#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint n, score1, score2, sum, maxx, total, x;
char a, b;
string name, maxn;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        cin >> name >> score1 >> score2 >> a >> b >> x;
        if (score1 > 80 && x > 0)       sum += 8000;
        if (score1 > 85 && score2 > 80) sum += 4000;
        if (score1 > 90)                sum += 2000;
        if (score1 > 85 && b == 'Y')    sum += 1000;
        if (score2 > 80 && a == 'Y')    sum += 850;
        total += sum;
        if (sum > maxx)
        {
            maxn = name;
            maxx = sum;
        }
    }
    cout << maxn << endl << maxx << endl << total;
    return 0;
}