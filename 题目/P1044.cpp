#include <bits/stdc++.h>
using namespace std;
vector<int> s1;
vector<int> s2;
int n, s3 = 1, sum;
void dfs()
{
    if (int(s1.size()) == n)
        sum++;
    if (s2.size())
    {
        s1.push_back(s2.back()); s2.pop_back();
        dfs();
        s2.push_back(s1.back()); s1.pop_back();
    }
    if (s3 <= n)
    {
        s2.push_back(s3); s3++;
        dfs();
        s3--; s2.pop_back();
    }
}
int main()
{
    cin >> n;
    dfs();
    cout << sum;
    return 0;
}