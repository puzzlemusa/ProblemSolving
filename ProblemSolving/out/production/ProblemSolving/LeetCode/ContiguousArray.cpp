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
    int findMaxLength(vector<int>& nums) {
        int ml = 0, i, mx = 0, c = 0;
        map<int, int> mp;
        
        mp[0] = -1;
        frn(i, sz(nums)) {
            c += nums[i] == 1 ? 1 : -1;
            if (mp.find(c) != mp.end())
                mx = max(mx, i - mp[c]);
            else
                mp[c] = i;
        }

        return mx;
    }
};
int main() {
    Solution sol;

    v = { 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0 };
    v = { 0,0,1,0,0,0,1,1 };
    //v = { 0, 1, 1, 0, 1, 1, 1, 0 };
    v = { 0, 0, 1, 1};
    cout << sol.findMaxLength(v);
}