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
    int climbStairs(int n) {
        return calc(n);
    }

    int calc(int n) {
        if (mem.find(n) != mem.end())
            return mem[n];
        else if (n == 0)
            return mem[n] = 1;
        else if (n <= 0)
            return mem[n] = 0;
        else {
            return mem[n] = calc(n - 1) + calc(n - 2);
        }
    }
};
int main() {
    Solution sol;
    cout << sol.climbStairs(0);
    return 0;
}