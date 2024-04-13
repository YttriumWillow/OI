#include <iostream>
#include <vector>

#define i64 long long
#define rep(i, l, r) for (int i = (l); i <= r; ++i)

const int N = 1e5;

struct BigInt {

    bool sign; // 0 - positive, 1 - negative
    std::vector<int> digit;

    BigInt() { digit.clear(); digit.push_back(0); sign = false; }
    BigInt(i64 x) {
        sign = false; digit.clear(); 
        if (!x) digit.push_back(0);
        if (x < 0) sign = true, x = -x;
        while (x) digit.push_back(x % 10), x /= 10;
    }

    void pop_back() { digit.pop_back(); }
    void resize(int x) { digit.resize(x); }
    int size() const { return digit.size(); } 
    int back() const { return digit.back(); }
    void clear() { digit.clear(); sign = false; }
    void push_back(int x) { digit.push_back(x); }
    int& operator [](int idx) { return digit[idx]; }
    bool is_zero() { return digit.size() == 1 && digit[0] == 0; }

    BigInt operator - () { 
        BigInt ret = *this; 
        return ret.sign = !ret.sign, ret; 
    }

    friend bool operator < (BigInt lhs, BigInt rhs) {
        if (lhs.sign ^ rhs.sign) return lhs.sign;
        if (lhs.size() != rhs.size()) return lhs.sign ^ (lhs.size() < rhs.size());

        for (int i = lhs.size() - 1; i >= 0; i--) 
            if (lhs[i] != rhs[i]) return lhs.sign ^ (lhs[i] < rhs[i]);
        return false;
    }

    friend bool operator >  (BigInt lhs, BigInt rhs) { return rhs < lhs; }
    friend bool operator <= (BigInt lhs, BigInt rhs) { return !(rhs < lhs); }
    friend bool operator >= (BigInt lhs, BigInt rhs) { return !(lhs < rhs); }
    friend bool operator == (BigInt lhs, BigInt rhs) { return lhs <= rhs && rhs <= lhs; }
    friend bool operator != (BigInt lhs, BigInt rhs) { return !(lhs == rhs); }

    friend BigInt operator + (BigInt lhs, BigInt rhs) {
        if (lhs.sign && rhs.sign) return -((-lhs) + (-rhs));
        if (!lhs.sign && rhs.sign) return lhs - (-rhs);
        if (lhs.sign && !rhs.sign) return rhs - (-lhs);
        
        BigInt ret; ret.clear(); 
        int t = 0, sizL = lhs.size(), sizR = rhs.size();
        for (int i = 0; i < std::max(sizL, sizR); i++) {
            if (i < sizL) t += lhs[i];
            if (i < sizR) t += rhs[i];
            ret.push_back(t % 10), t /= 10;
        }
        return (t ? ret.push_back(t) : void()), ret;
    }

    friend BigInt operator - (BigInt lhs, BigInt rhs) {
        if (lhs.sign && rhs.sign) return lhs + (-rhs);
        if (!lhs.sign && rhs.sign) return lhs + (-rhs);
        if (lhs.sign && !rhs.sign) return -((-lhs) + rhs);
        if (lhs < rhs) return -(rhs - lhs);
        
        BigInt ret; ret.clear(); 
        int t = 0, sizL = lhs.size(), sizR = rhs.size();
        for (int i = 0; i < sizL; i++) {
            t = lhs[i] - t;
            if (i < sizR) t -= rhs[i];
            ret.push_back((t + 10) % 10), t = (t < 0);
        }
        while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
        return ret;
    }

    friend BigInt operator * (BigInt lhs, BigInt rhs) {
        if (lhs.is_zero() || rhs.is_zero()) return 0;

        BigInt ret; ret.clear();
        ret.sign = lhs.sign ^ rhs.sign;

        int sizL = lhs.size(), sizR = rhs.size(); ret.resize(sizL + sizR + 1);
        for (int i = 0; i < sizL; i++)
            for (int j = 0; j < sizR; j++) {
                ret[i + j] += lhs[i] * rhs[j];
                ret[i + j + 1] += ret[i + j] / 10;
                ret[i + j] %= 10;
            }
        while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
        return ret;
    }

    friend BigInt operator / (BigInt lhs, int rhs) {
        BigInt ret; ret.clear();
        ret.sign = lhs.sign ^ (rhs < 0);

        int t = 0, sizL = lhs.size(); ret.resize(sizL);
        for (int i = sizL - 1; i >= 0; i--) {
            t = t * 10 + lhs[i];
            ret[i] = t / rhs; t %= rhs;
        }
        while (ret.size() > 1 && ret.back() == 0) ret.pop_back();
        return ret;
    }

    friend BigInt operator / (BigInt lhs, BigInt rhs) {
        BigInt ret; ret = 0;
        bool sign = lhs.sign ^ rhs.sign;
        lhs.sign = false; rhs.sign = false;

        BigInt t = 1;
        while (rhs <= lhs) rhs = rhs * 2, t = t * 2;
        while (t > 0) {
            if (rhs <= lhs) {
                lhs = lhs - rhs;
                ret = ret + t;
            }
            rhs = rhs / 2, t = t / 2;
        }
        return ret.sign = sign, ret;
    }

    friend BigInt operator % (BigInt lhs, BigInt rhs) {
        bool sign = lhs.sign;
        lhs.sign = false; rhs.sign = false;

        BigInt t = 1;
        while (rhs <= lhs) rhs = rhs * 2, t = t * 2;
        while (t > 0) {
            if (rhs <= lhs) lhs = lhs - rhs;
            rhs = rhs / 2, t = t / 2;
        }
        return lhs.sign = sign, lhs;
    }

    friend std::istream& operator >> (std::istream& is, BigInt &rhs) {
        std::string s; is >> s; rhs.clear();
        if (s[0] == '-') rhs.sign = true, s = s.substr(1);
        else rhs.sign = false;

        int p = 0; while (s[p] == '0') p++;
        if (p == s.length()) rhs.push_back(0), rhs.sign = false;
        for (int i = s.length() - 1; i >= p; i--) rhs.push_back(s[i] - '0');
        return is;
    }

    friend std::ostream& operator << (std::ostream& os, BigInt rhs) { 
        if (rhs.sign) os << "-";
        for (int i = rhs.size() - 1; i >= 0; i--) os << rhs[i];
        return os;
    }
    friend BigInt operator += (BigInt &lhs, BigInt rhs){ return lhs = lhs + rhs; }
};

int n; BigInt fib[N], sum;

int main(/*int argc, char const* argv[]*/) {
    std::cin >> n;

    sum = fib[1] = 1;
    rep (i, 2, n) {
        fib[i] = fib[i - 1] + fib[i - 2];
        sum += fib[i];
    }

    std::cout << sum << '\n';
}