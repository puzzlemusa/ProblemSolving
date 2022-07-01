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
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int x, y;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                x = m + n;
                y = m + n;
                if (mat[i][j] != 0) {
                    if (i - 1 >= 0)
                        x = mat[i - 1][j];
                    if (j - 1 >= 0)
                        y = mat[i][j - 1];
                    mat[i][j] = min(x, y) + 1;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                x = m + n;
                y = m + n;
                if (mat[i][j] != 0) {
                    if (i + 1 < m)
                        x = mat[i + 1][j];
                    if (j + 1 < n)
                        y = mat[i][j + 1];
                    mat[i][j] = min(mat[i][j], min(x, y) + 1);
                }
            }
        }

        return mat;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;
    vector<vector<int>> in = {{0, 0, 0},
                              {0, 1, 0},
                              {1, 1, 1}};

    in = {{0, 1, 0, 1, 1},
          {1, 1, 0, 0, 1},
          {0, 0, 0, 1, 0},
          {1, 0, 1, 1, 1},
          {1, 0, 0, 0, 1}};
    vector<vector<int>> res = sol.updateMatrix(in);

    return 0;
}