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
    int maxSubarraySumCircular(vector<int>& A) {
        int i, totMax = -maxn, currMax = 0, totMin = maxn, currMin = 0, tot = 0;

        frn(i, sz(A)) {
            currMax = max(currMax, 0) + A[i];
            totMax = max(totMax, currMax);

            currMin = min(currMin, 0) + A[i];
            totMin = min(totMin, currMin);
            tot += A[i];

        }

        return (totMax > 0 ? max(totMax, tot - totMin) : totMax);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif
    Solution sol;
    //vector<int> v = { 5, -3, 5 };
    //vector<int> v = { 1, -2, 3, -2 };
    //vector<int> v = { 3,-1,2,-1 };
    //vector<int> v = { 3, -2, 2, -3 };
    //vector<int> v = { -2, -3, -1 };
    //vector<int> v = { -2 };
    //vector<int> v = { 9,-4,-7,9 };
    vector<int> v = { 7, -10, 7, -10, 7 };

    cout << sol.maxSubarraySumCircular(v);
    //cin >> n;
    return 0;
}