#include <iostream>

#define longint long long
#define reg register

using namespace std;

bool isPrime[50000010];
longint Prime[3000010], cnt, n;

void GetPrime(longint n)
{
	for (reg int i = 1; i <= n; ++i)
        isPrime[i] = 1;
	isPrime[1] = 0;
	for (reg int i = 2; i <= n; ++i)
	{
		if (isPrime[i])
			Prime[++cnt] = i;
		for (reg int j = 1; j <= cnt && i * Prime[j] <= n; ++j) 
		{
			isPrime[i * Prime[j]] = 0;
			if (i % Prime[j] == 0) break;
		}
	}
	return;
}

int f[100];

int main()
{
	constexpr int N = 50;

	for (int n = 3; n <= N; ++n)
	{
		// cerr << "n = " << n << endl;
		for (int k = n - 2; k >= 0; --k)
		{
			// cerr << "k -> " << k * k << endl;
			if ((1ll * k * k) % n == 1) { f[n] = k; break; }
		}
	}

	for (int i = 1; i <= N; ++i)
		cout << f[i] << ",\n"[i == N];

	cout << "f[8] = " << f[8] << endl; // f[8] = 5
	cout << "f[15] = " << f[15] << endl; // f[15] = 11

	return 0;
}