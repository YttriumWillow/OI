#include <iostream>

long long a, b, k, r = 1, m = 998244353, _ = 499122177;

int main()
{
	std::cin >> a >> b >> k;
	for (int i = 1; i <= k; ++i)
	{
		if (!(i % a)) r = r * 2 % m : NULL;
		if (!(i % b) && r != 1) r = r * _ % m;
	}
	std::cout << r;
}