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
    int findJudge(int N, vector<vector<int>>& trust) {
        int i;
        map<int, int> t;

        frn(i, trust.size()) {
            t[trust[i][1]]++;
        }

        vector<pair<int, int>> pairs;
        for (auto itr = t.begin(); itr != t.end(); ++itr)
            pairs.push_back(*itr);

        sort(pairs.begin(), pairs.end(), [=](std::pair<int, int>& a, std::pair<int, int>& b)
            {
                return a.second > b.second;
            }
        );

        if (pairs.size() > 1 && pairs[0].second == pairs[1].second)
            return -1;
        else {
            frn(i, trust.size()) {
                if (trust[i][0] == pairs[0].first)
                    return -1;
            }
        }

        if (pairs.size() == 0)
            return 1;
        else
            return pairs[0].first;
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

    //vector<vector<int>> v = { {1,2} };
    //vector<vector<int>> v = { {1,3}, {2,3} };
    //vector<vector<int>> v = { {1,3}, {2,3},{3, 1} };
    //vector<vector<int>> v = { {1,2}, {2,3} };
    //vector<vector<int>> v = { {1,3}, {1,4}, {2,3}, {2,4}, {4,3} };
    vector<vector<int>> v = { };

    cout << sol.findJudge(4, v);
    //cin >> n;
    return 0;
}