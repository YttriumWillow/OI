#include<bits/stdc++.h>
using namespace std;
int a[1001][1001], sum[1001][1001];
int main(){
	freopen("num.in", "r", stdin);
	freopen("num.out", "w", stdout);
	int n, m;cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			cin >> a[i][j];
		
	for(int i = 1; i <= m; i++){
		int x, y;cin >> x >> y;
		if(x == 1 && y == 1){
			puts("-1");
			continue;
		}
		sum[1][1] = a[1][1];
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= i; j++){
				if(i == x && j == y) continue;
				if(i - 1 == x && j - 1 == y) sum[i][j] = a[i][j] + sum[i - 1][j];
				else if(i - 1 == x && j == y) sum[i][j] = a[i][j] + sum[i - 1][j - 1];
				else sum[i][j] = a[i][j] + max(sum[i - 1][j], sum[i - 1][j - 1]);
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans, sum[n][i]);
		}
		cout << ans << "\n";
	}
	return 0;
}
