#include <bits/stdc++.h>
#define longint long long
using namespace std;
int T, qwq;
string line;
int main()
{
    cin >> T;
    getline(cin, line);
    while (T--)
    {
        getline(cin, line);

        int len = line.size();
        bool flagl = 0, flagp = 0, check = 1, num = 0;
        int point = len - 1;
        int start, end;

        // special-before judge
        if (line == "-" || line == "-0" || line == "-.")
        {
            cout << "-1\n"; continue;
        }
        if (line == "0")
        {
            cout << "0\n"; continue;
        }
        // points & negetives
        for (int i = 0; i < len; i++)
        {
            if (flagl && line[i] == '-') { cout << "-1\n"; check = false; break; }
            if (flagp && line[i] == '.') { cout << "-1\n"; check = false; break; }
            if (line[i] == '-') flagl = true;
            if (line[i] == '.') { flagp = true; point = i; }
            if (line[i] >= '0' && line[i] <= '9') num = 1;
        }
        if (!check) continue;
        // math
        start = flagl; end = point;
        for (int i = point; i >= flagl; i--)
            if (line[i - 1] == '0') { start = i; break; }
        for (int i = point; i < len; i++)
            if (line[i + 1] == '0' || i == len - 1) { end = i; break; }
        bool pointpre = (line[start - 1] == '0' && line[start] == '.'
            && start - 1 >= flagl && line[start - 2] != '0');
        bool isok = (start == flagl && end == len - 1);
        bool pointover = line[end + 1] == '0' && line[end] == '.'
            && end + 1 < len && line[end + 2] != '0';
        if ((pointpre || isok) && !pointover && num)
        {
            for (int i = pointpre ? flagl : start; i <= end; i++)
                cout << line[i];
            cout << endl;
        }
        else cout << "-1\n";
        // if ()
    }
    return 0;
}