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

    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int start = 0;
        int end = nums.size();

        if(target > nums[nums.size()-1])
            return nums.size();

        while (start <= end) {
            mid = start + ((end - start) / 2);

            if (target == nums[mid])
                return mid;

            if (target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;

        }
        return start;
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
    v = {1,3,5,6};
    cout << sol.searchInsert(v, 5) << endl;
    cout << sol.searchInsert(v, 2) << endl;
    cout << sol.searchInsert(v, 7) << endl;
    cout << sol.searchInsert(v, 0) << endl;

    //cin >> n;
    return 0;
}