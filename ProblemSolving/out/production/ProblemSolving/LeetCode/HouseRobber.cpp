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

class Solution {
public:
    int rob(vector<int>& nums) {
        return max(calc(nums, sz(nums) - 1), calc(nums, sz(nums) - 2));
    }

    int calc(vector<int>& nums, int i) {
        if (mem.find(i) != mem.end())
            return mem[i];
        else if (i == 0)
            return mem[i] = nums[0];
        else if (i < 0)
            return mem[i] = 0;
        else {
            int a = calc(nums, i - 2) + nums[i];
            int b = calc(nums, i - 3) + nums[i];
            return mem[i] = max(a,b);
        }
    }
};
int main() {
    Solution sol;
    v = { 1, 2, 3, 1 };
    cout << sol.rob(v);
    return 0;
}