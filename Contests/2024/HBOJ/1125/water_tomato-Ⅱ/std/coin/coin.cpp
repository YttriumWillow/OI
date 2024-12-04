#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

#define MAXS 1000000
#define MAXN 1000
#define MAXL 20
#define Ssize 62
char s[MAXN+5]; int n, ans;
char w[MAXL+5];
inline int getidx( char c ) {
	if( c <= '9' && c >= '0' ) return c - '0';
	if( c <= 'Z' && c >= 'A' ) return c - 'A' + 10;
	if( c <= 'z' && c >= 'a' ) return c - 'a' + 10 + 26;
}
struct trie{
	int t[MAXS+5][Ssize];
	int vis[MAXS+5];
	int tot;
    void init(){
        for(int i=0;i<=tot;i++){
            for(int j=0;j<Ssize;j++) t[i][j]=0;
            vis[i]=0;
        }
        tot=0;
    }
	void insert( char *w , int len ) {
		int u = 0;
		FOR(i,1,len) {
			if( !t[u][getidx(w[i])] ) t[u][getidx(w[i])] = ++tot;
			u = t[u][getidx(w[i])];
		}
		ans += !vis[u];
		vis[u] = true;
	}
}K;
void solve() {
	scanf("%s", s+1);
	n = strlen(s+1);ans=0;
    K.init();
	FOR(i,1,n) FOR(j,i+1,n) {
		int len = 2;
		int f1 = i, f2 = j;
		w[1] = s[f1], w[2] = s[f2];
		while( f2 <= n ) {
			f2 = f1 + f2;
			f1 = f2 - f1;
			if( f2 > n ) break;
			w[++len] = s[f2];
		}
		K.insert(w, len);
	}
	printf("%d", ans);
}
signed main(){
    // for(int TT=1;TT<=20;TT++){
        // string input_file="coin"+to_string(TT)+".in";
        // string output_file="coin"+to_string(TT)+".out";
        freopen("coin.in","r",stdin);
        freopen("coin.out","w",stdout);
        // cout<<input_file<<endl;
        solve();
        // int T;
        // scanf("%d",&T);
        // while(T--) solve();
    // }
    return 0;
}