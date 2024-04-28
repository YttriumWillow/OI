#include <iostream>
#include <cstring>
#include <algorithm>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

using namespace std;

const i64 inf = 0x3f3f3f3f;

i64 n, l, maxL, f[2010];

pair<i64, i64> A[2010];
#define t first
#define p second

int main() {
    cin >> n >> l;

    rep (i, 1, n) {
        cin >> A[i].t >> A[i].p;
        maxL = std::max(maxL, A[i].p);
    }

    std::sort(A, A + n + 1);

    rep (i, 1, n) {
        if (A[i].t == A[i - 1].t) {
            rep (pos, 0, maxL)
                f[pos] += abs(pos - A[i].p);
        }
        else {
            i64 Min = inf;
            rep (pos, 0, maxL) {
                Min = min(Min, f[pos]);
                f[pos] = Min + abs(A[i].p - pos);
            }
        }
    }

    i64 res = inf;
    rep (pos, 0, maxL) res = min(res, f[pos]);

    cout << res << endl;

    return 0;
}