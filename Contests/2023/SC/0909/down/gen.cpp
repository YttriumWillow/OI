#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	long double l=a;l=l/b;
	printf("%.19Lf\n",l);
	return 0;
}
/*
12345786 82137483
0.1503063589128972944

1e-12
0.1503063589128972944
1371753 9126387

1e-9
1371753 9126387

*/
/*
12345787 82137483
0.1503063710876068603
*/