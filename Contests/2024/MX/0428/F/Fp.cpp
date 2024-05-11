#include<iostream>
using namespace std;
long long n, b, i, j, f[51][65536] = {}, light, compress = 0;
int main () {
    cin >> n >> b;
    for (i = 0; i < 1 << n; i++)
        for (j = 0; j < n; j++)
            f[0][i] += ((i & 1 << (j + 1) % n) > 0 ^ (i & 1 << j) > 0) * (1 << j);
    for (i = 1; i <= 50; i++)
        for (j = 0; j < 1 << n; j++)
            f[i][j] = f[i - 1][f[i - 1][j]];
    for (i = 1; i <= n; i++) {
        cin >> light;
        compress = compress << 1 | light;
    }
    for (i = 50; i >= 0; i--)
        if (1LL << i <= b) {
            b -= 1LL << i;
            compress = f[i][compress];
        }
    for (i = n - 1; i >= 0; i--)
        cout << ((compress & 1 << i) > 0) << endl;
    return 0;
}