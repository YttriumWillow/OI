#include <iostream>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

#define file(prob) freopen(prob".in", "r", stdin); freopen(prob".out", "w", stdout);

using namespace std;

i64 n;
/*
inline void seive(i64 n)
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
*/
/*
inline int factorint()
{
	return 0;
}

inline int sqrt_mod_iter_max(i64 a, i64 p) // this name is from sympy
{
	// if (isprime[p])
	return 0;
}
*/


int main()
{
	file("qidong");

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (i64 k = n - 2; k >= 0; --k)
			if ((k * k) % n == 1)
				{ cout << k << endl; break; }
	}
	/*
		You would like to solve this problem by Python:



		from sympy import *

		n = int(input())

		for T in range(n):
    		x = int(input())
    		res = list(sqrt_mod_iter(1, x)) # this means the solution of equation x**2 = a mod p
    		res.remove(x - 1) 				# of course there is a root which is x - 1

			# used Pollard-Rho & Miller-Rabin & CRT algorithms
			# so i said that the wheel other built is always useful

    		print(max(res))

    		# or you can solve in one line:  max(filter(lambda k: k <= n - 2, sqrt_mod_iter(1, n))) 
		


		this program only needs 450ms to pass through the biggest example
	*/
	return 0;
}
