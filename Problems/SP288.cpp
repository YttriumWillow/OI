#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int test_time = 8;

longint qpow(longint )

bool millerRabin(longint n)
{
    if (n < 3 || n % 2 == 0) return n == 2;
    longint a = n - 1, b = 0;
    while (a % 2 == 0) a /= 2, ++b;
    for (int i = 1, j; i <= test_time; ++i)
    {
        longint x = rand() % (n - 2) + 2, v = qpow(x, a, n);
        if (v == 1) continue;
        for (j = 0; j < b; ++j)
        {
            if (v == n - 1) break;
            v = (longint)v * v % n;
        }
        if (j >= b) return 0;
    }
    return 1;
}

int main()