#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int mp[12][10010];
int main ()
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		if (n == 0 )
			break;
		int ans = 0 ;
		for (int i = 1 ; i <= n ; i++ )
		{
			for (int j = 1 ; j <= m ; j++ )
			{
				scanf("%d", &mp[i][j]);
			}
		}
		for (int i = 0 ; i < 1 << n ; i++  )
		{
			int t = 0 ;
			for (int j = 1 ; j <= m ; j++ )
			{
				int p = 0 ;
				for (int k = 1 ; k <= n ; k++ )
				{
					if ( mp[k][j] == 1 )
					{
						if ( !(i >> (k - 1) & 1))
							p++;
					}
					else
					{
						if (i >> (k - 1) & 1)
							p++;
					}
				}
				if ( p <= n / 2 )
					p = n - p;
				t += p;
			}
			ans = max(ans, t);
		}
		printf("%d\n", ans);
	}
}
