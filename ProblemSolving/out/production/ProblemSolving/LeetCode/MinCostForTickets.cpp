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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int res = calc(days, costs);
        return res;
    }

    int calc(vector<int>& days, vector<int>& costs) {
        vector<int> m(days[sz(days) - 1] + 1, 0);
        
        int i, one, sev, tw;        
        frv(i, 1, days[sz(days)-1]+1) {
            if (isVacation(days, i)) {
                one = m[i - 1] + costs[0];
                sev = m[max(i - 7, 0)] + costs[1];
                tw = m[max(i - 30, 0)] + costs[2];
                m[i] = min(min(one, sev), tw);
            }
            else {
                m[i] = m[i - 1];
            }
        }
        
        return m[days[sz(days) - 1]];
    }

    bool isVacation(vector<int>& days, int day) {
        int i;
        frn(i, sz(days))
            if (days[i] == day)
                return true;
        return false;
    }
};
int main() {
    Solution sol;
    vector<int> d = { 1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29 };
    vector<int> c = { 3,14,50 };
    cout << sol.mincostTickets(d, c);
    return 0;
}