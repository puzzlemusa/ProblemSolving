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

#define frn(i,n) for(i=0;i<n;i++)
#define frN(i,n) for(i=1;i<=n;i++)
#define frr(i,n) for(i=n-1;i>=0;i--)
#define frv(i,a,n) for(i=a;i<n;i++)
#define frl(i,v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v,a) memset(v,a,sizeof(v))
#define pi (2*acos(0))
#include <bitset>
const int maxn = 2147483647;
vector<int>v;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        return find(nums, 0, nums.size()-1);
    }

    int find(vector<int>& nums, int l, int r) {
        int mid;

        if (r - l == 2) {
            if (nums[l] == nums[l + 1])
                return nums[r];
            else
                return nums[l];
        }

        if (l <= r) {
            mid = ceil((l + r+1) / 2);

            if (mid > 0 && mid < nums.size() - 1 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if((mid-1)%2==1)
                    return find(nums, l, mid - 1);
                else
                    return find(nums, mid + 1, r);
            }

            if (mid < nums.size()-1 && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 1)
                    return find(nums, l, mid - 1);
                else
                    return find(nums, mid + 1, r);
            }
        }

        return nums[r];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;

    vector<int> v = {1,1,2,3,3,4,4,8,8};
    //vector<int> v = { 3,3,7,7,10,11,11 };
    //vector<int> v = { 1,1,3,4,4,6,6 };
    //vector<int> v = { 1,2,2 };

    cout << sol.singleNonDuplicate(v);
    //cin >> n;
    return 0;
}