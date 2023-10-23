#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define rep(x, a, b) for (int x = (a); x <= (b); ++x)

#define file(prob) freopen(prob".in", "r", stdin), freopen(prob".out", "w", stdout);

using namespace std;

const int N = 1e5 + 10;

template<typename Tp>
struct BIT
{
    #define N 500010
    #define lowbit(x) (x & -x)
    Tp t1[N] = { 0 };
    Tp t2[N] = { 0 };
    int len = 0;
    inline void init(int n) { len = n; }
    inline void add(Tp x, Tp v)
    {
        for (reg int i = x; i <= len; i += lowbit(i))
            t1[i] += v, t2[i] += x * v;
    }
    inline Tp query(Tp x)
    {
        reg Tp res = 0;
        for (reg int i = x; i; i -= lowbit(i))
            res += (x + 1) * t1[i] - t2[i];
        return res;
    }
    inline Tp range(Tp l, Tp r) { return query(r) - query(l - 1); }
    inline void modify(Tp l, Tp r, Tp x) { add(l, x); add(r + 1, -x); }
};

namespace BIT
{
#define lowbit(x) ((x) & (-x))
int len = 0;
i64 t1[N], t2[N];
inline void add(int x, i64 v)
{
    for (int i = x; i <= len; i += lowbit(i))
        t1[i] += v, t2[i] += x * v;
}
inline i64 sum(int x)
{
    i64 res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += (x + 1) * t1[i] - t2[i];
    return res;
}
}

int main()
{
    file("seg");

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q; t.init(n);

    rep (i, 1, n) cin >> a[i];

    while (q--)
    {

    }


    return 0;
}