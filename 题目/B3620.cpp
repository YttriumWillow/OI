#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, ans;

inline longint get(char x)
{
    if (x >= '0' && x <= '9') return x - '0';
    else return x - 'A' + 10;
}

inline longint read()
{
    int x = 0; char ch;
    while (cin >> ch) { x = x * n + get(ch); }
    return x;
}

int main()
{
    cin >> n;
    ans = read();
    cout << ans << endl;
    return 0;
}