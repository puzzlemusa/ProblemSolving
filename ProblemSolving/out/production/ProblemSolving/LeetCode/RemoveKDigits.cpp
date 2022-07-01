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
    string removeKdigits(string num, int k) {
        int i, j;

        if (k == sz(num))
            return "0";

        frN(i, k) {
            bool r = false;
            frn(j, sz(num) - 1) {
                if (num[j] > num[j + 1]) {
                    num = num.erase(j, 1);
                    r = true;
                    break;
                }
            }

            if(!r)
                num = num.erase(j, 1);
        }

        frn(i, sz(num)) {
            if (num[i] == '0') {
                num = num.erase(i, 1);
                i--;
            }
            else
                break;
        }

        if (num == "")
            return "0";

        return num;
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

    cout << sol.removeKdigits("112", 1);
    //cin >> n;
    return 0;
}