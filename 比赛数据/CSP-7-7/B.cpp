#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar())if( c == '-' )f = -1;
	for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
	return x * f;
}

const int N = 1e6 + 5;

string s;
int n,c00,c11,sum1,sum0;
int a[N];

int main(){
	n = read();
	cin >> s;
	for(int i = 1;i <= n;i ++)a[i] = s[i - 1] - '0';
	for(int i = 1;i <= n;i ++){
		if( i == 1 ){
			if( a[i] == 1 )sum1 ++;
			else sum0 ++;
		}
		else{
			if( a[i] == a[i - 1] ){
				if( sum1 )sum1 ++;
				else sum0 ++;
			}
			else{
				if (sum1 && sum0) cerr << "fuck" << endl;
				if( sum1 ){
					c11 += sum1 - 1;
					sum1 = 0;
					sum0 ++;
				}
				else{
					c00 += sum0 - 1;
					sum0 = 0;
					sum1 ++;
				}
			}
		}
	}
	if( sum1 )c11 += sum1 - 1;
	else c00 += sum0 - 1;


	cout << sum0 << ' ' << sum1 << endl;
	cerr << c00 << ' ' << c11 << endl;

	cout << max(c11 , c00) + 1 << endl;
	return 0;
}
