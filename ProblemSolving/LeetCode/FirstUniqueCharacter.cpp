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
    int majorityElement(vector<int>& v) {
        map<int, int> m;
        map<int, int>::iterator mt;

        for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
            m[*it]++;
        }

        int mx = 0;
        int res = 0;
        for (mt = m.begin(); mt != m.end(); ++mt) {
            if (mt->second >= mx) {
                mx = mt->second;
                res = mt->first;
            }


        }

        return res;
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
	string n;
	cin >> n;
	vector<int> v()
	cout << sol.majorityElement(n);

	//cin >> n;
	return 0;
}