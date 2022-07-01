/*
ID: puzzlemusa
PROG:
LANG: C++
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iomanip>

using namespace std;

#define frn(i, n) for(i=0;i<n;i++)
#define frN(i, n) for(i=1;i<=n;i++)
#define frr(i, n) for(i=n-1;i>=0;i--)
#define frv(i, a, n) for(i=a;i<n;i++)
#define frl(i, v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v, a) memset(v,a,sizeof(v))
#define pi (2*acos(0))

const int maxn = 2147483647;
vector<int> v;


class Solution {
public:
    int myAtoi(string s) {
        int i;
        bool numStarted = false;
        bool plus = true;
        string sol;
        frn(i, sz(s)) {
            if (s[i] == '-') {
                if (numStarted) {
                    break;
                }
                plus = false;
                numStarted = true;
            } else if (s[i] == '+') {
                if (numStarted) {
                    break;
                }
                numStarted = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                sol += s[i];
                numStarted = true;
            } else {
                if (s[i] == ' ' && !numStarted) {
                    continue;
                } else {
                    break;
                }
            }
        }
        long tot = 0;
        int res = 0;
        frn(i, sz(sol)) {
            int d = int(sol[i]) - 48;
            double p = double(sz(sol) - 1 - i);
            if (d * pow(10.0, p) > pow(2.0, 31.0)) {
                if (plus)
                    res = pow(2.0, 31.0) - 1;
                else
                    res = 0 - pow(2.0, 31.0);
                break;
            }
            tot += (d * pow(10.0, p));

            if (plus) {
                if (tot > (pow(2.0, 31.0) - 1)) {
                    res = pow(2.0, 31.0) - 1;
                    break;
                } else {
                    res = tot;
                }

            }
            if (!plus) {
                if (tot > pow(2.0, 31.0)) {
                    res = 0 - pow(2.0, 31.0);
                    break;
                } else {
                    res = 0 - tot;
                }
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;
    cout << sol.myAtoi("094 -324") << endl;
    cout << sol.myAtoi("-94 -324") << endl;
    cout << sol.myAtoi("...-324") << endl;
    cout << sol.myAtoi("+94 .-324") << endl;
    cout << sol.myAtoi(" +94 .-324") << endl;
    cout << sol.myAtoi(" ") << endl;
    cout << sol.myAtoi(" 0") << endl;
    cout << sol.myAtoi("words and 987") << endl;
    cout << sol.myAtoi("+-12") << endl;
    cout << sol.myAtoi("20000000000000000000") << endl;
    cout << sol.myAtoi("9999999999999999999999999") << endl;
    cout << sol.myAtoi("-9999999999999999999999999") << endl;

    //cin >> n;
    return 0;
}