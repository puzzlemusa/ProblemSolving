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
map<int, int> mem;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int tot = m + n - 1;
        int x = m - 1;
        int y = n - 1;

        while (x >= 0 && y >= 0) {
            if (nums1[x] < nums2[y])
                nums1[tot--] = nums2[y--];
            else
                nums1[tot--] = nums1[x--];
        }

        while (y >= 0)
            nums1[tot--] = nums2[y--];
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {2, 5, 6};
    vector<int> v3 = {};
    vector<int> v4 = {1};
    sol.merge(v4, 1, v3, 0);
    return 0;
}