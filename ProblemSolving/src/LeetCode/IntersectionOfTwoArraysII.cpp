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

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        vector<int>res;
        for(int i = 0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        for(int i = 0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end()){
                mp[nums2[i]]--;
                if(mp[nums2[i]]>=0)
                    res.push_back(nums2[i]);
            }

        }
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
    vector<int> a = {4,9,5};
    vector<int> b = {9,4,9,8,4};
    vector<int> result = sol.intersect(a, b);
    //cin >> n;
    return 0;
}