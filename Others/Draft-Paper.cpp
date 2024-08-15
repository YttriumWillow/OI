#include <iostream>
#include <set>
#include <map>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

typedef std::pair<int, int> Pii;
struct comp {
    bool operator() (const Pii& A, const Pii& B) {
        return A.first ^ B.first ? A.first > B.first : A.second > B.second;
    }
};
std::map<int, int, std::greater<int>> M;
std::set<Pii, comp> S;

int main(/*int argc, char const* argv[]*/) {
    S.insert({1, 100});
    S.insert({2, 200});
    S.insert({3, 300});
    S.insert({4, 400});

    for (auto P : S) {
        std::cout << P.first << ' ' << P.second << '\n';
    }
}