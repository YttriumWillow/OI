#include <bits/stdc++.h>
#define each(i,T,b) for(int i=(T);i<=(b);++i)
#define eachr(i,T,b) for(int i=(T);i>=(b);--i)
typedef long long ll;
using namespace std;
constexpr int N=1e6+105;
 
inline int rd(){
	int w=1,r=0;char c=getchar();
	while(!isdigit(c)) (c=='-')and(w=-1),c=getchar();
	while(isdigit(c)) r=r*10+(c^48),c=getchar();
	return r*w;
}
 
char S[N],T[]={' ','n','o','i','p'};
 
inline int gc(char c){
	rep(i,1,4) if(T[i]==c) return i;
	return 0;
}
 
inline bool chk(int x,int p){
	for(int i=1,j=x;i<=4;){
		if(j==p) ++j;
		else if(T[i]!=S[j]) return 0;
		else ++i,++j;
	}
	return 1;
}
 
inline int ins(int x,int p,int q){
	for(int i=1,j=x;i<=4;){
		if(i==p || i==q) ++i;
		else if(T[i]!=S[j]) return 4;
		else ++i,++j;
	}
	if(!q || !p) return 1;
	return 2;
}
 
int main(){
	//freopen("A/A2.in","r",stdin);freopen("A/A2.out","w",stdout);
	auto sol = [](){
		int res=4;
		scanf("%S",S+1+5);
		
		int n=strlen(S+1+5);
		rep(i,1,n+10) if(!gc(S[i])) S[i]='_';
		//printf("%S\n",S+1+5);
		rep(i,1,n+5) if(chk(i,0)) res=0;
		rep(i,1,n+5){
			rep(j,i+1,i+3) if(chk(i,j)) res=min(res,1);
			rep(j,i+1,i+3){
				swap(S[j-1],S[j]);
				if(chk(i,0)) res=min(res,1);
				swap(S[j-1],S[j]);
			} 
			rep(j,i,i+3){
				char c=S[j];
				rep(k,1,4){
					S[j]=T[k];
					if(chk(i,j)) res=min(res,1);
					rep(T,1,4) res=min(res,ins(i,T,0)+1);
				}
				S[j]=c;
			}
			rep(j,1,4) rep(k,0,4) if(j!=k) res=min(res,ins(i,j,k));
			int tmp=0;
			rep(j,i,i+3) if(T[j-i+1]!=S[j]) ++tmp;
			res=min(res,tmp);
		}
		return res;
	};
	int T=rd();
	rep(t,1,T){
		//printf("%d:\n",t);
		printf("%d\n",sol());
	}
	return 0;
}
 