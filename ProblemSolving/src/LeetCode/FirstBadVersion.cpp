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

    int firstBadVersion(int n) {
        int mid;
        int start = 1;
        int end = n;

        while (start <= end) {
            mid = start + ((end - start) / 2);

            if (mid == 1) {
                if (isBadVersion(mid))
                    return 1;
                else return 2;
            }

            if (isBadVersion(mid) && !isBadVersion(mid - 1))
                return mid;

            if (isBadVersion(mid))
                end = mid - 1;
            else
                start = mid + 1;

        }
        return start;
    }

    bool isBadVersion(Long n) {
        if (n >= 4)
            return true;
        else
            return false;
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
    cout << sol.firstBadVersion(5);

    //cin >> n;
    return 0;
}