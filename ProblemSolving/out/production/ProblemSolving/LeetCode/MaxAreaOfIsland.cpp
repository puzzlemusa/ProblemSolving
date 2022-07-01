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

#define frn(i, n) for(i=0;i<n;i++)
#define frN(i, n) for(i=1;i<=n;i++)
#define frr(i, n) for(i=n-1;i>=0;i--)
#define frv(i, a, n) for(i=a;i<n;i++)
#define frl(i, v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v, a) memset(v,a,sizeof(v))
#define pi (2*acos(0))

#include <bitset>

const int maxn = 2147483647;
vector<int> v;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        int mx = 0;
        int size = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    size = DFS(grid, visited, i, j);
                    //cout << i << " " << j << " " << size << endl;
                    mx = max(mx, size);
                }
            }
        }

        return mx;
    }

    int DFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, int m, int n) {
        if (m == -1 || n == -1
            || m == grid.size() || n == grid[m].size()
            || visited[m][n] || grid[m][n] == 0)
            return 0;
        visited[m][n] = true;
        return 1 + DFS(grid, visited, m + 1, n) + DFS(grid, visited, m, n + 1)
               + DFS(grid, visited, m - 1, n) + DFS(grid, visited, m, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;

    //vector<vector<int>> v = { {1,1,1}, {1,1,0}, {1,0,1} };
    vector<vector<int>> v = {{0, 0, 1},
                             {1, 1, 0},
                             {0, 1, 0},
                             {0, 1, 1}};

    v = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
         {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
         {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
//    v = {{1,1,0,0,0},
//         {1,1,0,0,0},
//         {0,0,0,1,1},
//         {0,0,0,1,1}};
    cout << sol.maxAreaOfIsland(v);

//    int i, j;
//    frn(i, sz(r)) {
//        frn(j, sz(r[i])) {
//            cout << r[i][j] << " ";
//        }
//        cout << endl;
//    }
//    //cout << sol.floodFill(v, 1, 1, 2);
//    //cin >> n;
    return 0;
}