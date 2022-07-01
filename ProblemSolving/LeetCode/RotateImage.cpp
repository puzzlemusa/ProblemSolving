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
#define li(v) v.begin(), v.nd()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v, a) memset(v,a,sizeof(v))

typedef long long Long;
const int maxn = 1e9 + 10;

class Solution {
public:

    void rotate(vector<vector<int>> &matrix) {
        int temp;
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = i; j < ((n + 1) / 2) - 1; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    //freopen("D://input.txt", "r", stdin);
    //freopen("D://output.txt","w",stdout);
#endif

    Solution sol;
    vector<vector<int>> a = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
    vector<vector<int>> b = {{5,  1,  9,  11},
                             {2,  4,  8,  10},
                             {13, 3,  6,  7},
                             {15, 14, 12, 16}};
    vector<vector<int>> c = {{5}};
    vector<vector<int>> d = {{1, 2},
                             {3, 4}};
    sol.rotate(a);
    //cin >> n;
    return 0;
}