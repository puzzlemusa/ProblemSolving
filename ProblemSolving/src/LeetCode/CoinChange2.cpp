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
    int change(int amount, vector<int>& coins) {
        vector<int> m(amount + 1);
        m[0] = 1;
        int i, j;
        frn(i, sz(coins)) {
            frv(j, coins[i], amount+1) {
                m[j] += m[j - coins[i]];
            }
        }
        return m[amount];
    }

    int calc(int amount, int c, vector<int>& coins) {
        if (mem.find(make_pair(amount, c)) != mem.end())
            return mem[make_pair(amount, c)];
        else if (amount == 0)
            return mem[make_pair(amount, c)] = 1;
        else if (amount < 0 || c == sz(coins))
            return mem[make_pair(amount, c)] = 0;
        else {
            mem[make_pair(amount, c)] = calc(amount - coins[c], c, coins) + calc(amount, c + 1, coins);
        }
        return mem[make_pair(amount, c)];
    }
};
int main() {
    Solution sol;
    vector<int> r = { 1,2,5 };
    cout << sol.change(5, r);
    return 0;
}