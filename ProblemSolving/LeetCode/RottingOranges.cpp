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
    int orangesRotting(vector<vector<int>> &grid) {
        int freshOrange = 0;
        queue<pair<int, int>> q;
        int level = 0;
        int numberInIteration;
        int c, r;
        vector<vector<int>> dimension = {{1,  0},
                                         {0,  1},
                                         {-1, 0},
                                         {0,  -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    freshOrange++;
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }

        while (!q.empty()) {
            numberInIteration = q.size();
            while (numberInIteration-- != 0) {
                pair<int, int> pr = q.front();
                q.pop();
                //cout << pr.first << " " << pr.second<< endl;
                for (int x = 0; x < 4; x++) {
                    c = pr.first + dimension[x][0];
                    r = pr.second + dimension[x][1];

                    if (c >= 0 && c < grid.size() && r >= 0 && r < grid[0].size()) {
                        if (grid[c][r] == 1) {
                            grid[c][r] = 2;
                            q.push(make_pair(c,r));
                            freshOrange--;
                            //cout << pr.first << " " << pr.second << " " << c << " " << r << endl;
                        }
                    }
                }
            }
            level++;
        }
        if (freshOrange > 0)
            return -1;
        if (level == 0)
            return 0;
        return level - 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;
    vector<vector<int>> in = {{2, 1, 1},
                              {1, 1, 0},
                              {0, 1, 1}};
    cout << sol.orangesRotting(in) << endl;

    in = {{2, 1, 1},
          {0, 1, 1},
          {1, 0, 1}};
    cout << sol.orangesRotting(in) << endl;

    in = {{0, 2}};
    cout << sol.orangesRotting(in) << endl;

    in = {{2, 1, 1, 1, 2},
          {1, 1, 0, 1, 1},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0}};
    cout << sol.orangesRotting(in)<< endl;

    in = {{0}};
    cout << sol.orangesRotting(in)<< endl;

    return 0;
}