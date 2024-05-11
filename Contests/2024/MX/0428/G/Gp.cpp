#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define NMAX 12
#define infinite 1000000000
int dp[1 << NMAX];
int main() {
    //freopen("haywire.in","r",stdin);
    //freopen("haywire.out","w",stdout);
    int n;
    scanf("%d", &n);
    int nbr[13][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &nbr[i][0], &nbr[i][1], &nbr[i][2]);
        nbr[i][0]--;	nbr[i][1]--;	nbr[i][2]--;
    }
    dp[0] = 0;
    for (int subset = 1; subset < (1 << n); subset++) {
        int pending_links = 0;
        for (int i = 0; i < n; i++) {//计算链出去的线 
            if (subset & (1<<i)) {
                pending_links += 3-(((subset >> nbr[i][0]) & 1) +
                                 ((subset >> nbr[i][1]) & 1) +
                                 ((subset >> nbr[i][2]) & 1));
            }
        }
        dp[subset] = infinite;
        for (int i = 0; i < n; i++) {
            if (subset & (1 << i)) {
                int cost = pending_links - 3 + 2 * (((subset >> nbr[i][0]) & 1) +
                                           ((subset >> nbr[i][1]) & 1) +
                                           ((subset >>  nbr[i][2]) & 1));
                dp[subset] = min(dp[subset], dp[subset & ~(1<<i)] + cost);
            }
        }
    }
    printf("%d\n", dp[(1 << n) - 1]);
}
