#include<bits/stdc++.h>
#define ld long double
#define ll long long
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T; std::cin >> T;
	while (T--)
	{
		ll a, b, c; std::cin >> a >> b >> c;
		if (a == b && b != c) { std::cout << 0 << "\n"; continue; }
		if (a == 1 && b == 1 && c == 1) { std::cout << -1 << "\n"; continue; }
		if (a == 1 && b == 1) { std::cout << 0 << "\n"; continue; }
		int ans = 0;
		if (b < a || c < b) { std::cout << (b == c) << "\n"; continue; }
		if (a) { ll tmp = c; while (tmp % b == 0) tmp /= b; ans += (tmp == 1); }
		std::vector<int> tmp;
		while (c > 0) tmp.push_back(c % b), c /= b;
		__int128 tmpb = 0, v = 1;
		for (auto x : tmp)
		{
			tmpb += v * x;
			v = v * a;
		}
		ans += (tmpb == b);
		std::cout << ans << "\n";
	}
	return 0;
}