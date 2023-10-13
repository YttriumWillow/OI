#include <iostream>
#include <bitset>
#include <ctime>

using namespace std;

const int N = 1e9 + 10;

int *prime = new int[N];

// 欧拉筛 
inline void Euler(int n)
{
	prime[0] = 0;
	prime[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; ++j)
		{
			prime[i * prime[j]] = 1;
			if (!(i % prime[j])) { break; }
		}
	}
}


bitset<1000000010> isprime;
// bitset 优化埃氏筛
inline void Eratosthenes(int n)
{
	prime[0] = 0;
    isprime.set(); isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (isprime[i])
            for (int j = i << 1; j <= n; j += i)
                if (isprime[j] == 1)
                    isprime[j] = 0;
    for (int i = 1; i <= n; ++i)
    	if (isprime[i])
    		prime[++prime[0]] = i;
}

int main()
{
	// compare;

	double stx = clock();
	Euler(1e9);
	cout << (((double)clock() - stx) / CLOCKS_PER_SEC) << endl;

	stx = clock();
	Eratosthenes(1e9);
	cout << (((double)clock() - stx) / CLOCKS_PER_SEC) << endl;

}