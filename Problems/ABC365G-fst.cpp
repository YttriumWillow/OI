#pragma GCC optimize(2)

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 200001

int n, m, q;
set<pair<int, int>> st[MAXN];
map<pair<int, int>, int> R;
vector<int> T[MAXN], S[MAXN];

int gans(int x, int y) {
    int res = 0;
    for (int i = 0, j = -1; i < T[x].size(); ++i) {
        while (j < (int)T[y].size() - 1 && T[y][j + 1] <= T[x][i])
            ++j;
        if (!~j) continue;
        res += (i & 1 ? 1 : -1) * (S[y][j] + (j & 1 ? 0 : T[x][i] - T[y][j]));
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1, t, x; i <= m; ++i) {
        cin >> t >> x;
        T[x].push_back(t);
    }
    for (int i = 1; i <= n; ++i) {
        if (T[i].empty()) continue;
        S[i].resize(T[i].size()); S[i][0] = 0;
        for (int j = 1; j < T[i].size(); ++j) {
            S[i][j] = S[i][j - 1] + (j & 1 ? T[i][j] - T[i][j - 1] : 0);
        }
    }
    cin >> q;
    for (int a, b; q; --q) {
        cin >> a >> b;
        if (R.count({ a, b })) {
            cout << R[{a, b}] << '\n';
            continue;
        }
        auto it = *st[a].lower_bound({ b, 0 });
        if (it.first == b) {
            R[{a, b}] = it.second;
            cout << it.second << '\n'; continue;
        }
        int k = gans(a, b);
        st[a].insert({ b, k });
        
        R[{a, b}] = k; cout << k << '\n';
    }
}