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
    typedef long long Long;

    string reverseWords(string s) {
        bool wordStarted = false;
        int wordSize = 0;
        int firstLetterIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (wordStarted) {
                    reverse(s.begin() + firstLetterIndex, s.begin() + firstLetterIndex + wordSize);
                    wordStarted = false;
                }
                wordSize = 0;
            } else {
                if (!wordStarted)
                    firstLetterIndex = i;
                wordSize++;
                wordStarted = true;
                if(i==s.size()-1)
                    reverse(s.begin() + firstLetterIndex, s.begin() + firstLetterIndex + wordSize);
            }
        }
        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif
    typedef long long Long;
    Solution sol;
    cout << sol.reverseWords("Let's take LeetCode contest") << endl;

    //cin >> n;
    return 0;
}