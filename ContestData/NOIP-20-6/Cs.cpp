#include <bits/stdc++.h>
#define each(i,a,b) for(int i=(a);i<=(b);++i)
#define eachr(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;
using namespace std;
constexpr int N=1010,P=998244353;
 
inline int rd(){
	int r=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) r=r*10+(c^48),c=getchar();
	return r;
}
 
int n,p,m,cnt[N],f[N][N],g[55][N][55];
int vis[N],coef[N],tmp[N],stk[N],top;
 
inline int qpow(int a,int x=P-2){
	int r=1;
	while(x){
		if(x&1) r=1ll*r*a%P;
		a=1ll*a*a%P,x>>=1;
	}
	return r;
}
 
inline int C(int x,int y){
    int r=1;
    eachr(i,x,x-y+1) r=1ll*r*i%P;
    each(i,1,y) r=1ll*r*qpow(i)%P; 
    return r;
}
 
inline int Add(int x,int y){return x+y>=P ? x+y-P : x+y;}
inline void Pls(int &x,int y){x = x+y>=P ? x+y-P : x+y;}
inline int Mul(int x,int y){return 1ll*x*y%P;}
 
int main(){
    n=rd(),p=rd(),m=rd(); 
    int len=0,mul=1;
    each(i,1,n){
        if(vis[mul%p]){
            int L=len-vis[mul%p]+1;n-=len;
            each(j,1,L){
                cnt[mul]+=(n/L+(n%L>=j)); 
                mul=mul*10%p;
            }
            break;
        }
        cnt[mul%p]++,len++,vis[mul%p]=i,mul=mul*10%p;
    }
 
    f[0][0]=1;
    each(i,1,m) each(j,0,m) 
		if(f[i-1][j]) each(k,1,9) Pls(f[i][j+k],f[i-1][j]); 
    g[0][0][0]=1;
    each(i,0,p-1){
        each(j,0,min(m,cnt[i])) coef[j]=C(cnt[i],j);
        each(y,0,m){
            tmp[y]=0;
            each(x,0,min(y,cnt[i])) if(f[x][y]) Pls(tmp[y],Mul(coef[x],f[x][y])); 
        }
        top=0;
        each(j,0,m) if(tmp[j]) stk[++top]=j;
        each(j,0,m) each(k,0,p-1) 
			if(g[i][j][k]){
            	for(int o=1,y,w;y=stk[o],y<=m-j&&o<=top;++o){
            		w=(k+y*i)%p,Pls(g[i+1][j+y][w],Mul(g[i][j][k],tmp[y])); 	
				}
    		}
    }
    int ans=0;
    each(i,0,m) Pls(ans,g[p][i][0]),printf("%d ",ans);
    return 0; 
}