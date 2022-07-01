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

const int maxn = 1e9 + 10;
vector<vector<char>>v;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1)
			return s;

		string *str = new string[numRows];

		int row = 0, step = 1;
		for (int i = 0; i < sz(s); ++i)
		{
			str[row].push_back(s[i]);

			if (row == 0)
				step = 1;
			else if (row == numRows - 1)
				step = -1;

			row += step;
		}

		s.clear();
		for (int j = 0; j < numRows; ++j)
		{
			s.append(str[j]);
		}

		return s;
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
	string s;

	cin >> s >> n;

	cout << sol.convert(s, n);


	//cin >> n;
	return 0;
}