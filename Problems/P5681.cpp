#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read();
using namespace std;
longint a, b, c;
int main()
{
    cin >> a >> b >> c;
    cout << (a * a > b * c ? "Alice" : "Bob") << endl;
    return 0;
}