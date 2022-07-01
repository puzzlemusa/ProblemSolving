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
map<pair<int, int>, int> memo;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if(triangle.size()==1)
            return triangle[0][0];
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v1 = {{2},
                              {3, 4},
                              {6, 5, 7},
                              {4, 1, 8, 3}};
    vector<vector<int>> v2 = {{-10},
    };
    cout << sol.minimumTotal(v2);
    return 0;
}