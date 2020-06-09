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
map<int, int> mem;
vector<int> d = { 0,6,19 };
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        if (sz(s) == 0)
            return true;
        if (sz(t) == 0)
            return false;

        while (i < sz(s) && j < sz(t)) {
            if (s[i] == t[j])
                i++;
            j++;
        }
        if (i == sz(s))
            return true;
        else
            return false;
    }    
};
int main() {
    Solution sol;
    cout << sol.isSubsequence("axc", "bahxdch");
    return 0;
}