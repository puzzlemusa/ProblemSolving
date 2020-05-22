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

#define frn(i,n) for(i=0;i<n;i++)
#define frN(i,n) for(i=1;i<=n;i++)
#define frr(i,n) for(i=n-1;i>=0;i--)
#define frv(i,a,n) for(i=a;i<n;i++)
#define frl(i,v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v,a) memset(v,a,sizeof(v))
#define pi (2*acos(0))
#include <bitset>
const int maxn = 2147483647;
vector<int>v;

class Solution {
public:
    string frequencySort(string s) {

        if (sz(s) == 0)
            return s;

        map<char, int> mp;
        vector<pair<char, int>> pr;
        int i, j;
        string res;

        frn(i, sz(s)) {
            mp[s[i]]++;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it)
            pr.push_back(*it);

        sort(pr.begin(), pr.end(), [=](std::pair<char, int>& a, std::pair<char, int>& b) {
            return a.second > b.second;
        });

        frn(i, sz(pr)) {
            j = pr[i].second;
            while (j--) {
                res.push_back(pr[i].first);
            }
        }

        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.frequencySort("") << endl;
}