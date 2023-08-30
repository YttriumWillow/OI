#include <iostream>

using namespace std;

// 欧拉筛 
inline void Euler(int n)
{
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


// bitset 优化埃氏筛
inline void Eratosthenes(int n)
{
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