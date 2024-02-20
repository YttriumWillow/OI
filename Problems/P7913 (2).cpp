#include <bits/stdc++.h>
#define qwq puts("fzy qwq ~");
#define longint long long
#define reg register
#define _read =read()
using namespace std;
inline longint read()
{
    longint x = 0, sgn = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') sgn = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    return x * sgn;
}
struct Flight
{
    longint arrive, leave;
    Flight(){}
    Flight(longint _x, longint _y): arrive(_x), leave(_y) {}
    friend bool operator < (Flight _x, Flight _y)
    {
        if (_x.arrive == _y.arrive) return _x.leave < _y.leave;
        else return _x.arrive < _y.arrive;

    }
};
Flight internalFlight[100010];
Flight internationalFlight[100010];
longint n, m1, m2;
priority_queue<Flight> waitqueue;
priority_queue<int> bridgequeue;
void calc(longint )
{
    
}
int main()
{
    n _read; m1 _read; m2 _read;
    for (int i = 1; i <= m1; i++)
    {
        internalFlight[i].arrive _read;
        internalFlight[i].leave _read;
    }
    for (int i = 1; i <= m2; i++)
    {
        internationalFlight[i].arrive _read;
        internationalFlight[i].leave _read;
    }
    sort(internalFlight + 1, internalFlight + m1 + 1);
    sort(internationalFlight + 1, internationalFlight + m2 + 1);
    
    return 0;
}