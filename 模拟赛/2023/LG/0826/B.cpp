#include <iostream>
int n, a[1000010] = { 1, 1 };
int main()
{
	std::cin >> n;
	for (int l = 2; l <= n / 2 + 1; ++l)
	{
		a[l] = (l & 1) ? l - 1 : n - l + 2;
		a[n - l + 2] = (l & 1) ? l : n - l + 1;
	}
	if (!(n & 1)) a[n / 2 + 1] = n / 2 + !!(n % 4);
	for (int i = 1; i <= n; ++i)
		std::cout << a[i] << ' ';
}