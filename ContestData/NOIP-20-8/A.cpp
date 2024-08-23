#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<deque>
#include<string>
#include<bitset>
#include<vector>
#include<cstdio>
#include<random>
#include<complex>
#include<cstdlib>
#include<climits>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);
using namespace std;
// #define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
// char buf[1<<21],*p1=buf,*p2=buf;
const long long _base=107374183;
inline long long read()
{
    char c=getchar();long long x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;
    return x;
}
inline void write(long long x)
{
	int tot=(x==0),writetemp[30]={0};
    long long t;
	while(x) t=x/10,writetemp[++tot]=x-(t<<1)-(t<<3),x=t;
    for(int i=tot;i>=1;i--) putchar(writetemp[i]+'0');
    putchar('\n');
	return ;
}
int slen,tlen,ans=1;
char s[1000010];
char t[1000010];
int now[30];
int nxt[500010][30];
int main()
{
	file("string");
    // freopen("s.out","r",stdin);
    // freopen("a.out","w",stdout);
    scanf("%s%s",s+1,t+1);
    slen=strlen(s+1),tlen=strlen(t+1);
    for(int i=slen;i>=1;i--) now[s[i]-'a']=i;
    for(int i=slen;i>=0;i--)
    {
        for(int j=0;j<26;j++) nxt[i][j]=now[j];
        if(i) now[s[i]-'a']=i;
    }
    int now=0;
    for(int i=1;i<=tlen;i++)
    {
        if(nxt[now][t[i]-'a']==0) return printf("-1\n"),0;
        if(nxt[now][t[i]-'a']<=now) ans++;
        now=nxt[now][t[i]-'a'];
        // printf("%d\n",now);
    }
    printf("%d\n",ans);
    return 0;
}
/*
*/