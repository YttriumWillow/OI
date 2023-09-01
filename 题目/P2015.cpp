#include <iostream>

#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define push push_back

using namespace std;

struct Branch // 树枝 666
{
    int to, w;
    Branch() {}
    Branch(int _t, int _w) : to(_t), w(_w) {}
};

vector<Branch> appletree[110];

int n, q;
int u, v, w;
int f[110][110];

void update(int &_x, int _y) { _x = max(_x, _y); }

void dfs(int rt)
{
    if (appletree[rt].empty()) return;
    for (auto x : appletree[rt])
    {
        dfs(x.to);
        for (int i = q; i >= 1; i--) // 艹 vector 好像没法判子树大小，但好像炸不掉
            for (int j = i; j >= 1; j--)
                update(f[rt][i], f[rt][i - j] + f[x.to][j - 1] + x.w);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v >> w;
        appletree[u].push(Branch(v, w));
    }
    dfs(1);
    cout << f[1][q] << '\n';
    return 0;
}