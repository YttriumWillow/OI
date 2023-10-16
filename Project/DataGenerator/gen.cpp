#include "testlib.h"
#include <iostream>
#include <regex>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)

using namespace std;

const int N = 1e5 + 10;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    int m = opt<int>("m");

    cout << n << ' ' << m << endl;

    rep(T, 1, m)
    {
        int a = rnd.next(1, n);
        int b = rnd.next(1, n);
        cout << a << ' ' << b << endl;
    }

    return 0;
}