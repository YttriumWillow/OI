#include<bits/stdc++.h>
#define max(A,B) (A<B?B:A)
#define min(A,B) (A>B?B:A)
#define bug cout<<"I AK IOI"<<endl;
#define gc getchar
using namespace std;
const int N=2e4+17;

inline void print(int x) {if (x < 0) putchar('-'), x = -x; if(x > 9) print(x / 10); putchar(x % 10 + '0');}
inline int read(){int res = 0, f = 0; char ch = gc();for(; !isdigit(ch); ch = gc()) f |= (ch == '-'); for(;isdigit(ch);ch=gc()) res = (res << 1) + (res << 3) + (ch ^ '0');return f ? -res :res;}

int n,mp[N],a,Max=-1,Min=1e9;
int jil[N*2],ans=1;

int cmp(int q,int p){return q>p;}

signed main(){
    n=read();
    for(int i=1;i<=n;++i) mp[a=read()]++,Min=min(Min,a),Max=max(Max,a);
    for(int i=Min*2;i<=Max*2;i++)
    {
        for(int j=1;;j++)
        {
            if(j>i-j) break;
            if(i-j==j) jil[j]+=mp[j]/2;
            else

            jil[i]+=min(mp[j],mp[i-j]);
        }
    }
    sort(jil+1,jil+1+Max*2,cmp);
    cout<<jil[1];
    for(int i=2;i<=Max*2+1;i++){
        if(jil[i]!=jil[i-1]) break ;
        ans++;
    }
    cout<<' '<<ans;
}   