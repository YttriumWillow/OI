#include<iostream>
#include<cstdio>
using namespace std;
#define long long long 
struct modein{
	modein operator >>(long &x){
		x=0;char c=getchar();
		while(c<'0'||c>'9')c=getchar();
		while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
		return (modein){};
	}
}qin;
long x1=9223372036854775807,x2,y1=9223372036854775807,y2,z1=9223372036854775807,z2,x,y,z;
int main(){
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	long n;qin>>n; 
	for(int i=0;i<n;i++){
		qin>>x>>y>>z;
		x1=min(x1,x),x2=max(x2,x);
		y1=min(y1,y),y2=max(y2,y);
		z1=min(z1,z),z2=max(z2,z);
	}
	if((x2-x1+1)*(y2-y1+1)*(z2-z1+1)!=n)puts("NO");
	else puts("YES");
	return 0;
}
