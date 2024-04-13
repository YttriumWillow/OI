#include <iostream>
#include <cstring>
#include <map>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

std::string M[] = { "", "M", "MM", "MMM" };
std::string C[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
std::string X[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
std::string I[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

std::map<char, int> m = {
    {'I', 1}, {'V', 5},
    {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500},
    {'M', 1000}
};
int toInt(std::string v) {
    int res = 0;
    for (auto p : v) { res += m[p]; }
    return res;
}
std::string toRoman(int v) {
    return M[v / 1000] + C[v % 1000 / 100] + X[v % 100 / 10] + I[v % 10];
}

std::string A, B;

int main(/*int argc, char const* argv[]*/) {
    while (std::cin >> A && A != "#") {
        std::cin >> B;
        int r = std::abs(toInt(A) - toInt(B));
        std::cout << ((r) ? toRoman(r) : "ZERO") << '\n';
    }
}
