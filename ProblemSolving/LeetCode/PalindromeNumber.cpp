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
    bool isPalindrome(int x) {
        string s = std::to_string(x);
        string r = s;
        reverse(r.begin(), r.end());

        return r == s ? true : false;
    }

    bool isPalindrome1(int x) {
        int t = x;
        int r = 0;
        while (t > 0) {
            r = (r * 10) + (t % 10);
            t /= 10;
        }

        return r == x ? true : false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;
    cout << sol.isPalindrome1(0) << endl;
    cout << sol.isPalindrome1(10) << endl;
    cout << sol.isPalindrome1(-10) << endl;
    cout << sol.isPalindrome1(-101) << endl;
    cout << sol.isPalindrome1(101) << endl;

    //cin >> n;
    return 0;
}