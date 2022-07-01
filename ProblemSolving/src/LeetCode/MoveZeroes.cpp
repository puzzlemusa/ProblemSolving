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

const int maxn = 2147483647;
vector<int> v;


class Solution {
public:
    typedef long long Long;

    void moveZeroes(vector<int> &nums) {
        // not the best, extra space
        vector<int> res(nums.size(), 0);
        int i, j = 0;
        frn(i, sz(nums)) {
            if (nums[i] != 0)
                res[j++] = nums[i];
        }
        nums = res;
    }

    void moveZeroes1(vector<int> &nums) {
        int snowBallSize = 0, i, temp;
        frn(i, sz(nums)) {
            if (nums[i] == 0)
                snowBallSize++;
            else {
                temp = nums[i];
                nums[i] = nums[i-snowBallSize];
                nums[i-snowBallSize] = temp;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif
    typedef long long Long;
    Solution sol;
    v = {0, 1, 0, 3, 12};
    v = {0};
    sol.moveZeroes1(v);

    //cin >> n;
    return 0;
}