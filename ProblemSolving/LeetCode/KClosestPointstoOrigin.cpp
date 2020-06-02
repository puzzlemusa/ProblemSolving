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
vector<pair<float, pair<int, int>>> mp;
vector<vector<int>> r;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int i;
        float dis;
        frn(i, sz(points)) {
            dis = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            mp.push_back(make_pair(dis, make_pair(points[i][0], points[i][1])));
        }

        sort(mp.begin(), mp.end(), [=](std::pair<float, pair<int, int>>& a, std::pair<float, pair<int, int>>& b)
            {
                return a.first < b.first;
            }
        );

        vector<int> t;
        frn(i, K) {
            t.push_back(mp[i].second.first);
            t.push_back(mp[i].second.second);
            r.push_back(t);
            t.clear();
        }

        return r;
    }
};
int main() {
    Solution sol;

    vector<vector<int>> t = { {3,3} ,{5,-1},{-2,4} };
    vector<vector<int>> res = sol.kClosest(t, 2);
}