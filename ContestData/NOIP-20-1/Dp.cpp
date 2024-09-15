1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
int n, num[111111], al;
long double c[111111], x, y, psi[111111], cur, pro, prod, p[111111], ans, rr, sm;
vector<pair<long double, long double> > a[111111];
vector<pair<pair<long double, long double>, int> > all;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%Lf", &c[i]);
        scanf("%d", &num[i]);
        for (int j = 1; j <= num[i]; j++) {
            scanf("%Lf%Lf", &x, &y);
            y /= 1000.00;
            a[i].push_back(make_pair(x, y));
        }
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
        cur = c[i]; pro = 0.00;
        bool flg = 0;
        for (int j = 0; j < (int)a[i].size() - 1; j++) {
            pro += a[i][j].second;
            if (cur < pro * (a[i][j].first - a[i][j + 1].first)) {
                psi[i] = a[i][j].first - cur / pro;
                flg = 1;
                break;
            }
            else cur -= pro * (a[i][j].first - a[i][j + 1].first);
        }
        if (!flg) psi[i] = a[i].back().first - cur;
        pro = 0.00;
        for (int j = 0; j < a[i].size(); j++) {
            if (a[i][j].first < psi[i]) all.push_back(make_pair(a[i][j], i));
            else pro += a[i][j].second;
        }
        if (pro > eps) all.push_back(make_pair(make_pair(psi[i], pro), i));
    }
    sort(all.begin(), all.end()); prod = 1.00;
    reverse(all.begin(), all.end());
    for (int i = 1; i <= n; i++) p[i] = 1.00;
    for (int i = 0; i < all.size(); i++) {
        rr = prod;
        prod /= p[all[i].second];
        p[all[i].second] -= all[i].first.second;
        prod *= p[all[i].second];
        rr -= prod;
        ans += (all[i].first.first * rr);
    }
    ans = fmax(0.00, ans);
    printf("%.12Lf\n", ans);
    return 0;
}