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
map<int, set<int>> dis;
map<int, int> ass;
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int i;
        
        frn(i, sz(dislikes)) {
            dis[dislikes[i][0]].insert(dislikes[i][1]);
            dis[dislikes[i][1]].insert(dislikes[i][0]);
        }

        
        for (auto it = dis.begin(); it != dis.end(); ++it) {
            if (ass.find(it->first) == ass.end())
                if (!DFS(it->first, 1))
                    return false;
        }
        
        return true;
    }

    bool DFS(int root, int c) {
        if (ass.find(root) != ass.end()) {
            return ass[root] == c;
        }
        else {
            ass[root] = c;
            set<int> ad = dis[root];
            for (auto itS = ad.begin(); itS != ad.end(); ++itS) {
                if (!DFS(*itS, c==1 ? 2 : 1))
                        return false;   
            }
        }

        return true;
    }
};
int main() {
    Solution sol;

    //vector<vector<int>> t = { {1,2} ,{2,3},{3,4},{4,5}, {1,5} };
    vector<vector<int>> t = { {1,2} ,{1,3},{2,4} };
    //vector<vector<int>> t = { {1, 2}, { 3, 4 }, { 4, 5 }, { 3, 5 } };
    //vector<vector<int>> t = { {1, 2}, { 3, 4 }, { 4, 5 }, { 3, 5 } };
    cout << sol.possibleBipartition(4, t);
}