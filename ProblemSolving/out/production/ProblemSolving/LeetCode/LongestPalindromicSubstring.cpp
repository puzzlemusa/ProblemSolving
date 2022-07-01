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

typedef long long Long;

vector<int>v;

class Solution {
public:
	string longestPalindrome(string s) {
		if(sz(s) < 2)
			return s;

		string r;
		int mxl = 0;

		int i;
		frn(i, sz(s)) {
			if (isPal(s, i - mxl - 1, i)) {
				r = s.substr(i - mxl - 1, mxl + 2);
				mxl += 2;
			}

			else if (isPal(s, i - mxl, i)) {
				r = s.substr(i - mxl, mxl + 1);
				mxl++;
			}
		}

		return r;
	}

    bool isPal(string s, int b, int e) {
        if (b < 0)
            return false;

        s = s.substr(b, e - b + 1);

        string s1 = s;
        reverse(li(s1));

        return s == s1;
    }
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Solution sol;
	int n, i, j;

	cout << sol.longestPalindrome("cadabb");

	//cin >> n;
	return 0;
}