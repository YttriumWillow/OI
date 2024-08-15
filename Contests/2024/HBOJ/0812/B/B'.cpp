const int mo = 998244353;
int n, n3, n6, ans;
int a[1200010], las[1200010], pla[200010], to[1200010];
struct node { int num; int ans; }dp[1200010];
inline int jia(int x, int y) { x += y; if (x >= mo)x -= mo; return x; }
inline void solve(int bg, int fro) {
    register int i, j;//cout<<"   "<<bg<<" "<<fro<<endl;
    memset(dp, 0, sizeof(dp));
    dp[fro - bg] = (node){ 1,1 };
    for (i = fro - bg + 1; i <= n3; ++i) {
        dp[i] = dp[i - 1];
        if (las[bg + i] > bg) {
            if (dp[las[bg + i] - bg - 1].num + 1 > dp[i].num) {
                dp[i] = dp[las[bg + i] - bg - 1]; ++dp[i].num;
            }
            else if (dp[las[bg + i] - bg - 1].num + 1 == dp[i].num)
                dp[i].ans = jia(dp[i].ans, dp[las[bg + i] - bg - 1].ans);
        }//cout<<i<<