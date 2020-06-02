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
map<pair<int, int>, int> mem;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = -maxn, mxSoFar = 0, i;
        frn(i, sz(nums)) {
            mxSoFar = max(mxSoFar + nums[i], nums[i]);
            mx = max(mx, mxSoFar);
        }
        return mx;
    }

    int maxSubArray(vector<int>& nums, int i, int j) {

    }
};
int main() {
    Solution sol;
    v = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << sol.maxSubArray(v);
    return 0;
}