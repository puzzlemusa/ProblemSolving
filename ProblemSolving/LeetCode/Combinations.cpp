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
    void print(vector<int> v, int k) {
        int i;
        frn(i, k) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void swap(vector<int> &v, int i, int j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    void permutation(vector<int> v, int start, int k, vector<vector<int>> &res) {
        int i;
        if (start == k) {
            print(v, k);
            vector<int> r;
            for (int j = 0; j < k; j++) {
                r.push_back(v[j]);
            }
            res.push_back(r);
        } else {
            int max = min(end, end + 1 - data.length + index);
            for (i = start; i < v.size() - start; i++) {
                if (i != start)
                    swap(v, start, i);
                permutation(v, start + 1, k, res);
            }
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> res;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        permutation(nums, 0, k, res);
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
    vector<vector<int>> result = sol.combine(4, 2);
    //cin >> n;
    return 0;
}