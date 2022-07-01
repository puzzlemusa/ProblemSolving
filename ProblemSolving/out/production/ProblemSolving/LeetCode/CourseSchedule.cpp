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
map<int, set<int>> adj;
map<int, bool> visited;
map<int, bool> disconvered;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int i;

        frn(i, sz(prerequisites)) {
            adj[prerequisites[i][0]].insert(prerequisites[i][1]);
        }

        for (auto it = adj.begin(); it != adj.end(); ++it) {
            if (visited.find(it->first) == visited.end())
                if (!DFS(it->first))
                    return false;
        }
        
        return true;
    }

    bool DFS(int root) {
        disconvered[root] = true;
        set<int> ad = adj[root];
        for (auto itS = ad.begin(); itS != ad.end(); ++itS) {
            if (disconvered.find(*itS) != disconvered.end()) {
                return false;
            }
            if (!DFS(*itS))
                return false;
        }
        disconvered.erase(root);
        visited[root] = true;

        return true;
    }
};
int main() {
    Solution sol;

    //vector<vector<int>> t = { {1,2} ,{2,3},{3,4},{4,5}, {1,5} };
    //vector<vector<int>> t = { {1,2} ,{1,3},{2,4} };
    //vector<vector<int>> t = { {1, 2}, { 3, 4 }, { 4, 5 }, { 3, 5 } };
    //vector<vector<int>> t = { {1, 2}, { 3, 4 }, { 4, 5 }, { 3, 5 } };
    vector<vector<int>> t = { {0,1} ,{1,0} };
    //vector<vector<int>> t = { {1,0}, {2,0} };
    cout << sol.canFinish(4, t);
}