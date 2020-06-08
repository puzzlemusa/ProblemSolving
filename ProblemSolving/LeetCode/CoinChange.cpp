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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> m(amount + 1, amount + 1);
        m[0] = 0;
        int i, j;
        frn(i, sz(coins)) {
            frv(j, coins[i], amount + 1) {
                m[j] = min(m[j], m[j - coins[i]] + 1);
            }
        }
        return m[amount] > amount ? -1 : m[amount];
    }

    int calc(int amount, int c, vector<int>& coins) {
        if (amount == 0)
            return 0;
        if (amount < 0 || c == sz(coins))
            return maxn;
        if (mem.find(amount) != mem.end())
            return mem[amount];

        int mn = maxn;
        for (int i = 0; i < sz(coins); i++) {
            mn = min(mn, calc(amount - coins[i], i, coins) + 1);
        }
        mem[amount] = mn;
        return mn;
    }
};
int main() {
    Solution sol;
    vector<int> r = { 1,2,5 };
    cout << sol.coinChange(r, 11);
    return 0;
}