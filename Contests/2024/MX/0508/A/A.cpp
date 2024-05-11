#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)
#define file(prb) freopen(prb".in", "r", stdin); freopen(prb".out", "w", stdout);

int n, st; std::string S[10010];

std::string f(std::string& S) {
    std::string res;
    int i = st;
    while (std::isdigit(S[i]) and S[i] != '.') {
        res += S[i]; ++i;
    }
    return res;
}

bool cmp(std::string A, std::string B) {
    if (A == B) return 0;
    else if (A.size() != B.size()) return A.size() < B.size();
    else return A < B;
}

int main(/*int argc, char const* argv[]*/) {
    file("data");

    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;
    rep (i, 1, n) { std::cin >> S[i]; }

    for (auto c : S[1]) {
        if (!std::isdigit(c)) ++st;
        else break;
    }

    std::string name = S[1].substr(0, st);
    std::vector<std::string> v;

    rep (i, 1, n) { v.push_back(f(S[i])); }

    std::sort(v.begin(), v.end(), cmp);

    for (auto x : v) {
        std::cout << name << x << ".in\n";
    }

}