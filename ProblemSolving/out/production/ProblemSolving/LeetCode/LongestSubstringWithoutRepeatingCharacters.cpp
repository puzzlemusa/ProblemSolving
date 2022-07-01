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

const int maxn = 1e9 + 10;
vector<int> v;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j = 0, mx = 0;
        unordered_map<char, int> mp;

        frn(i, sz(s)) {
            char c = s.at(i);

            if (mp.find(c) == mp.end())
                mp[c]++;
            else {
                while (true) {
                    if (s.at(j) == c) {
                        j++;
                        break;
                    } else {
                        mp.erase(s.at(j));
                    }
                    j++;
                }
            }

            mx = max(mx, i - j + 1);
        }

        return mx;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    //freopen("D://input.txt", "r", stdin);
    //freopen("D://output.txt","w",stdout);
#endif
    int n, i, j;
    Solution sol;
    string s;

    cout << sol.lengthOfLongestSubstring("pwwkew");

    //cin >> n;
    return 0;
}