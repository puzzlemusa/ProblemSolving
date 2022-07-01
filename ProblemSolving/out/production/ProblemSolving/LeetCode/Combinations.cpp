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

    //faster when nCn, skip n iteration.
    void permutation(vector<int> data, vector<int> temp, int start, int k, int index, vector<vector<int>> &res) {
        int i;
        if (index == k) {
            res.push_back(temp);
        } else {
            for (i = start; i < data.size() && data.size() - i + 1 < k - index; i++) {
                temp[index] = data[i];
                permutation(data, temp, i + 1, k, index + 1, res);
            }
        }
    }

    // slower
    void permutation1(vector<int> data, vector<int> temp, int start, int k, int index, vector<vector<int>> &res) {
        int i;
        if (index == k) {
            res.push_back(temp);
        } else {
            for (i = start; i < data.size() ; i++) {
                temp[index] = data[i];
                permutation1(data, temp, i + 1, k, index + 1, res);
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> res;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        vector<int> temp(k);
        permutation(nums, temp, 0, k, 0, res);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    //freopen("D://input.txt", "r", stdin);
    //freopen("D://output.txt","w",stdout);
#endif

    Solution sol;
    vector<vector<int>> result = sol.combine(4, 4);
    //cin >> n;
    return 0;
}