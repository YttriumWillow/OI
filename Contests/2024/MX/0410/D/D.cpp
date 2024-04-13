#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

typedef __gnu_pbds::priority_queue<int, std::greater<int>> heap;

const int N = 1e3 + 10;

int n, m, Q;
int C[N][N];
std::vector<int> col[N], row[N];

int main(/*int argc, char const* argv[]*/) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n >> m >> Q;

    rep (i, 1, n) rep (j, 1, m) {
        std::cin >> C[i][j];
        col[i].push_back(C[i][j]);
        row[j].push_back(C[i][j]);
    }

    rep (i, 1, n) { sort(col[i].begin(), col[i].end(), std::greater<int>()); }
    rep (i, 1, m) { sort(row[i].begin(), row[i].end(), std::greater<int>()); }

    while (Q--) {
        int x, y, k;
        std::cin >> x >> y >> k;

        std::vector<int> &X = col[x];
        std::vector<int> &Y = row[y];

        int p1 = 0, p2 = 0, cnt = 0;
        while (p1 < m and p2 < n and cnt < k) {
            X[p1] > Y[p2] ? ++p1 : ++p2;
            ++cnt;
        }
        while (p1 < m and cnt < k) {
            ++p1; ++cnt;
        }
        // if (cnt == k) 


    }

}