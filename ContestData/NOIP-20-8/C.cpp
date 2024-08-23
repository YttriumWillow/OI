#include <bits/stdc++.h>
using namespace std;
#define Pii pair<int,int>
#define mp make_pair
#define pb push_back

    
int n;
int a[3005], b[3005];
std::vector<Pii> ans2;
signed main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> a[i], b[i] = i;
    std::vector<int> S, T;
    for (int i = 1; i <= n; i++) S.pb(a[i]);
    for (int j = 1; j <= n; j++) T.pb(b[j]);
    calc(S, T);

    std::cout << ans.size() << '\n';
    for (auto i = ans.rbegin(); i != ans.rend(); ++i)
        std::cout << i->first << ' ' << i->second << '\n';
    return 0;
}