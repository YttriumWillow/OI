#include <iostream>

#include <vector>

#define i64 long long 
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

inline void change(vector<int> p)
{
	p.push_back(6);
}

inline void fuck(vector<int> p)
{
	for (auto x : p)
	{
		cout << x << ' ';
	}
	cout << endl;
	change(p);
	for (auto x : p)
	{
		cout << x << ' ';
	}
	cout << endl;
}

int main()
{
	fuck({ 1, 1, 4, 5, 1, 4 });
	return 0;
}