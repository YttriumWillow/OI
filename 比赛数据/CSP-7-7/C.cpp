#include<bits/stdc++.h>

#define int long long
#define lowbit(x) ((x) &- (x))

using namespace std;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar())if( c == '-' )f = -1;
	for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
	return x * f;
}

inline void file(string name){
	string FileIn = name + ".in",FileOut = name + ".ans";
	freopen(FileIn.c_str() , "r" , stdin);
	freopen(FileOut.c_str() , "w" , stdout);
}

const int N = 5e5 + 100, P = 998244353;

int n, q;
int a[N],ans[N],aa[N],b[N];
char str[N];

inline void midsort(int l,int r){
	if( l == r )return;
	int mid = (l + r) >> 1,i = l,j = mid + 1,p = l;
	midsort( l , mid );
	midsort( mid + 1 , r );
	while( i <= mid && j <= r ){
		if( aa[i] <= aa[j] )b[p ++] = aa[i ++];
		else{
			b[p ++] = aa[j ++];
			ans[0] += mid - i + 1;
		}
	}
	while( i <= mid )b[p ++] = aa[i ++];
	while( j <= r )b[p ++] = aa[j ++];
	for(int o = l;o <= r;o ++)aa[o] = b[o];
}

int flag = 1;

signed main () {
    n = read();
    q = read();
    for (int i = 1; i <= n; i++)
        aa[i] = a[i] = read();
    deque<int> Q(a + 1, a + 1 + n);
    //ans[0] = NXD();
    midsort( 1 , n );
    scanf("%s", str + 1);
    for (int i = 1; i <= q; i++){
        if (str[i] == '1') {
            ans[i] = n * (n - 1) / 2 - ans[i - 1];
            flag ^= 1;
        } else {
            if (flag) {
                int tmp = Q.front();
                Q.pop_front();
                Q.push_back(tmp);
                ans[i] = ans[i - 1] - (tmp - 1) + (n - tmp);
            } else {
                int tmp = Q.back();
                Q.pop_back();
                Q.push_front(tmp);
                ans[i] = ans[i - 1] - (tmp - 1) + (n - tmp);
            }
        }
    }
    ans[0] = 0;
    for(int i = q,mul = 1;i;i--){
		ans[0] = (ans[0] + ans[i] % P * mul % P)% P;
		mul = mul * 233 % P;
	}
    cout << ans[0] << endl;
    return 0;
}