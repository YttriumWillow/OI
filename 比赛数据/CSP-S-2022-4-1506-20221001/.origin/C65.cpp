#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=5e3+10,bs=43;

char s[N];
int n,tot,r1[N],r2[N],ans;
vector<int>c[30];
ull h1[N],h2[N],pw[N];

ull get1(int l,int r){return h1[r]-h1[l-1]*pw[r-l+1];}
ull get2(int l,int r){return h2[l]-h2[r+1]*pw[r-l+1];}

int main(){
	freopen("palinilap.in","r",stdin);
	freopen("palinilap.out","w",stdout);
	scanf("%s",s+1); n=strlen(s+1);
	pw[0]=1; for(int i=1;i<=n;i++) pw[i]=pw[i-1]*bs;
	for(int i=1;i<=n;i++) h1[i]=h1[i-1]*bs+s[i]-'a';
	for(int i=n;i>=1;i--) h2[i]=h2[i+1]*bs+s[i]-'a';
	for(int i=1;i<=n;i++){
		c[s[i]-'a'].push_back(i);
		int l=1,r=min(i-1,n-i),mid;
		while(l<=r){
			mid=l+r>>1;
			if(get1(i-mid,i-1)==get2(i+1,i+mid)) l=mid+1;
			else r=mid-1;
		}
		r1[i]=l; tot+=l;
	}
	for(int i=1;i<n;i++){
		int l=1,r=min(i,n-i),mid;
		while(l<=r){
			mid=l+r>>1;
			if(get1(i-mid+1,i)==get2(i+1,i+mid)) l=mid+1;
			else r=mid-1;
		}
		r2[i]=r; tot+=r;
	}
	ans=tot;
	// printf("%d\n",tot);
	for(int i=1;i<=n;i++){
		int now=tot;
		for(auto v:c[s[i]-'a']){
			if(v==i) continue;
			int mid=v+i>>1;
			if((v&1)==(i&1)) now-=max(0,r1[mid]-abs(mid-v));
			else now-=max(0,r2[mid]-(abs(v-i)>>1));
		}
		for(int j=0;j<26;j++){
			if(s[i]-'a'==j) continue;
			int tmp=now;
			for(auto v:c[j]){
				int mid=v+i>>1;
				if((v&1)==(i&1)){
					if(r1[mid]<abs(mid-v)) continue;
					int l=r1[mid]+1,r=min(mid-1,n-mid),len;
					while(l<=r){
						len=l+r>>1;
						if(get1(mid-len,mid-r1[mid]-1)==get2(mid+r1[mid]+1,mid+len)) l=len+1;
						else r=len-1;
					}
					tmp+=l-r1[mid];
				}else{
					if(r2[mid]<(abs(v-i)>>1)) continue;
					int l=r2[mid]+2,r=min(mid,n-mid),len;
					while(l<=r){
						len=l+r>>1;
						if(get1(mid-len+1,mid-r2[mid]-1)==get2(mid+r2[mid]+2,mid+len)) l=len+1;
						else r=len-1;
					}
					tmp+=r-r2[mid];
				}
			}
			ans=max(ans,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}
