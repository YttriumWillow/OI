#include <bits/stdc++.h>
#define longint long long
using namespace std;
longint ans, n;
int main()
{
    string a, b;
    cin >> a;
    getchar();

    transform(a.begin(), a.end(), a.begin(), ::tolower);
    getline(cin, b);
    b.insert(0, " ");

    a = a + ' ';
    a.insert(a.begin(), ' ');
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    if (b.find(a) == -1)
    {
        cout << "-1";
    }
    else
    {
        while ( b.find(a, n) != -1 )
        {
            ans++;
            n = b.find(a, n) + 1;
        }
        cout << ans << " ";
        cout << b.find(a);
    }
}
