#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

typedef struct Pair_tag {
	double a;
	double b;
	Pair_tag(){}
	Pair_tag(double a_, double b_){
		a = a_;
		b = b_;
	}
} Pair;

ll sum[200007];
Pair pr[200007];

bool operator <(const Pair a, const Pair b){
	if (a.a != b.a) return a.a < b.a;
	return a.b < b.b;
}

int main(){
	int n;
	double base, suf = 0.0, ans = 1e9;
	cin >> n;
	for (register int i = 1; i <= n; i++){
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	base = 1.0 * sum[n] / n;
	for (register int i = 1, j = 1, x = n; i < n; i++){
		int len = n - i;
		j++;
		if (1.0 * (sum[x] - sum[j - 1]) / len > base){
			j--;
			x--;
		}
		pr[i] = Pair(base - 1.0 * (sum[x] - sum[j - 1]) / len, 1.0 * (sum[x + 1] - sum[j]) / len - base);
	}
	sort(pr + 1, pr + n);
	for (register int i = n - 1; i >= 1; i--){
		ans = min(ans, pr[i].a + suf);
		suf = max(suf, pr[i].b);
	}
	printf("%.10lf", ans);
	return 0;
}