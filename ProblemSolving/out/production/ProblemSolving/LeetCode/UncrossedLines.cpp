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
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        return calc(sz(A) - 1, sz(B) - 1, A, B);
    }

    int calc(int i, int j, vector<int>& A, vector<int>& B) {
        if (i < 0)
            return 0;
        if (j < 0)
            return 0;

        if (mem.find(make_pair(i, j)) != mem.end())
            return mem[make_pair(i, j)];

        int x = j;
        while (x >= 0 && A[i] != B[x])
            x--;

        int p1 = calc(i - 1, j, A, B);
        int p2 = calc(i-1, x-1, A, B);
        int con = x >= 0 ? 1 : 0;
        int res = max(p1, p2 + con);
        mem[make_pair(i, j)] = res;
        
        return res;
    }
};
int main() {
    Solution sol;
    vector<int >v1 = { 1,3,7,1,7,5 };
    vector<int >v2 = { 1,9,2,5,1 };

    cout << sol.maxUncrossedLines(v1, v2);
}