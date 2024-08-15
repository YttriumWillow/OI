#include <iostream>
#include <cstring>

#define i64 long long 
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

int a[5][5], b[5][5];

void rev(int x, int y) {
    static int dx[] = { 0, 1, 0, -1, 0 };
    static int dy[] = { 0, 0, 1, 0, -1 };
    rep (i, 0, 4) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 or xx > 4 or yy < 0 or yy > 4) continue;
        b[xx][yy] ^= 1;
    }
}

void solve() {
    rep (i, 0, 4) rep (j, 0, 4) {
        char ch; std::cin >> ch; a[i][j] = ch - '0';
    }    
    int res = 100;
    rep (S, 0, 31) {
        memcpy(b, a, sizeof a); int cnt = 0;
        rep (i, 0, 4) if (S >> i & 1) {
            rev(0, i); ++cnt;
        }
        rep (i, 1, 4) rep (j, 0, 4) if (!b[i - 1][j]) {
            rev(i, j); ++cnt;
        }
        bool f = 1; 
        rep (j, 0, 4) if (!b[4][j]) {
            f = 0; break;
        } 
        if (f) res = std::min(res, cnt);
    }

    std::cout << (res <= 6 ? res : -1) << '\n';
}

int main(/*int argc, char const *argv[]*/) {
    int T; std::cin >> T;
    while (T--) { solve(); }
}