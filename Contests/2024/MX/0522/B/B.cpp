#include <iostream>
#include <vector>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

int n, K; char ch;
bool fck[11][8][8];
std::vector<int> s[11];

bool check(int fk, int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n and fck[fk][x][y];
}

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n >> K;
    rep (i, 0, K) {
        int l = n - 1, r = 0, u = n - 1, d = 0;
        rep (j, 0, n - 1) rep (k, 0, n - 1) {
                std::cin >> ch;
                fck[i][j][k] = (ch == '#');
                if (fck[i][j][k]) {
                    u = std::min(u, j); d = std::max(d, j);
                    l = std::min(l, k); r = std::max(r, k);
                }
            }
        s[i] = { l, r, u, d };
    }

    // from here
    for (int i = 1; i <= K; i++) {
        for (int j = i + 1; j <= K; j++) {
            for (int xi = s[i][3] - n + 1; xi <= s[i][2]; xi++) {
                for (int yi = s[i][1] - n + 1; yi <= s[i][0]; yi++) {
                    for (int xj = s[j][3] - n + 1; xj <= s[j][2]; xj++) {
                        for (int yj = s[j][1] - n + 1; yj <= s[j][0]; yj++) {
                            bool o = true;
                            for (int x = 0; x < n; x++) {
                                for (int y = 0; y < n; y++) {
                                    bool ifk = check(i, x + xi, y + yi);
                                    bool jfk = check(j, x + xj, y + yj);
                                    if (ifk && jfk) {
                                        o = false;
                                        break;
                                    }
                                    if (fck[0][x][y] != (ifk || jfk)) {
                                        o = false;
                                        break;
                                    }
                                }
                                if (!o) { break; }
                            }
                            if (o) {
                                std::cout << i << " " << j << '\n';
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    // to here...   powered by GPT.
    // i don't wanna to tell him(?) how to use rep(i, l, r)
    // so's that.
}

