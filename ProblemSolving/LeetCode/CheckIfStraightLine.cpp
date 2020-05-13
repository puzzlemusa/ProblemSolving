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
    bool checkStraightLine(vector<vector<int>>& v) {
        int i, j;
        float slope, t, x,y;
        if ((v[1][0] - v[0][0]) == 0)
            slope = 0;
        else
            slope = (v[1][1] - v[0][1]) / (v[1][0] - v[0][0]);
        frv(i, 1, v.size()) {
            y = (v[i][1] - v[0][1]);
            x = (v[i][0] - v[0][0]);

            if (x == 0)
                t = 0;
            else
                t = y / x;
            if (t != slope)
                return false;
        }

        return true;
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

    //vector<vector<int>> v = { {1, 2},{2, 3},{3, 4},{4, 5},{5, 6},{6, 7} };
    //vector<vector<int>> v = { {1, 1},{2, 2},{3, 4},{4, 5},{5, 6},{7, 7} };
    vector<vector<int>> v = { {-7, -3},{-7, -1},{-2, -2},{0, -8},{2, -2},{5, -6},{5, -5},{1, 7} };

    cout << sol.checkStraightLine(v);
    //cin >> n;
    return 0;
}