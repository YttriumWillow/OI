#include <iostream>
#include <ctime>
#include <cmath>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 31;
const int inf = 1e9;

int n, m, ans, a[N];

namespace SA
{
const double d = 0.98;
const double T0 = 1e4;
const double TE = 1e-4;
const double TIMELMT = 0.5;
const int ROUND = 9;

inline double frnd(double l, double r) { return 1.0 * rand() / RAND_MAX * (r - l) + l; }
inline int rndpos(int m) { return rand() % m + 1; }

inline int calc()
{
    static int cnt[2], res; cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; ++i)
        cnt[i & 1] += a[i];
    res = abs(cnt[0] - cnt[1]);
    ans = min(ans, res);
    return res;
}

inline void run()
{
    for (double T = T0; T >= TE; T *= d)
    {
        int p = rndpos(n), q = rndpos(n);

        int prev = calc();
        swap(a[p], a[q]);
        int suff = calc();

        if (exp(-(suff - prev) / T) > frnd(0, 1)) ; // accept the answer
        else swap(a[p], a[q]);
    }
}

inline void timerun(double t = TIMELMT) { while((double)clock() / CLOCKS_PER_SEC < t) run(); }
inline void roundrun(int t = ROUND) { while(t--) run(); }
}
using namespace SA;

inline void solve()
{
    ans = inf;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    roundrun();
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    srand(time(0));

    int T; cin >> T;
    while (T--) solve();
    return 0;
}