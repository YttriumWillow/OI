#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, x, pos;
int score[355];
int card[11];
int f[41][41][41][41];

void update(int &x, int y) { x = max(x, y); }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &score[i]);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &x), ++card[x];

    f[0][0][0][0] = score[1];
    for (int x = 0; x <= card[1]; ++x)
        for (int y = 0; y <= card[2]; ++y)
            for (int z = 0; z <= card[3]; ++z)
                for (int q = 0; q <= card[4]; ++q)
                {
                    pos = x + y * 2 + z * 3 + q * 4 + 1;
                    if (x != 0) update(f[x][y][z][q], f[x - 1][y][z][q] + score[pos]);
                    if (y != 0) update(f[x][y][z][q], f[x][y - 1][z][q] + score[pos]);
                    if (z != 0) update(f[x][y][z][q], f[x][y][z - 1][q] + score[pos]);
                    if (q != 0) update(f[x][y][z][q], f[x][y][z][q - 1] + score[pos]);
                }
    cout << f[card[1]][card[2]][card[3]][card[4]] << endl;
    return 0;
}