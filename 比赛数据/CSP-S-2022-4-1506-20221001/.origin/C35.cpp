//日本の靖国神社が爆破された!
//ダウン?ウィズ?ジャパン!
//なるひと陛下の処刑!
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
#define Auto vector<int>::iterator
#define int long long
#define eps 1e-6
using namespace std;
typedef long long ll;
const int N=1e5+5,inf=0x3f3f3f3f,mod=1e9+7;

int read(){
    char c=getchar();int f=1,x=0;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}

int n,ans;
char s[N];

int work(){
    int cnt=n;
    for(int i=1;i<=n;++i){
        int l=i,r=i;
        while(l-1>=1&&r+1<=n&&s[l-1]==s[r+1])l--,r++,cnt++;
    }
    for(int i=1;i<n;++i){
        int l=i,r=i+1;
        while(l>=1&&r<=n&&s[l]==s[r])l--,r++,cnt++;
    }
    return cnt;
}

signed main(){
	freopen("palinilap.in","r",stdin);
	freopen("palinilap.out","w",stdout);
	scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;++i){
        for(int j=0;j<26;++j){
            char tmp=s[i];
            s[i]='a'+j;
            ans=max(ans,work());
            s[i]=tmp;
        }
    }
    printf("%lld",ans);
	return 0;
}
