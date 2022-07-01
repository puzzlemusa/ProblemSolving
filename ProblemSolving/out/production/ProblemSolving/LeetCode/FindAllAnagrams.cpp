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
    vector<int> findAnagrams(string s, string p) {
        vector<int> r, cap;
        int i, j;
        cap.resize(26);

        frn(i, sz(p)) {
            cap[p[i] % 97]++;
        }

        frn(i, sz(s)) {
            cap[s[i] % 97]--;
            if (i >= sz(p) - 1) {
                frn(j, 26) {
                    if (cap[j] != 0)
                        break;
                }

                if (j == 26) {
                    r.push_back(i - sz(p) + 1);
                    //if(i< sz(s)-1 && s[i - (sz(p) - 1)] == s[i+1])
                        //cap[s[i - (sz(p) - 1)] % 97]++;
                }
                cap[s[i - (sz(p) - 1)] % 97]++;
            }
        }
        return r;
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
    string s, p;
    cin >> s >> p;

    v= sol.findAnagrams(s, p);
    //cin >> n;
    return 0;
}