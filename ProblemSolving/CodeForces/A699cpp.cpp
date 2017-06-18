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

const int maxn = 1e9 + 10;
typedef __int64 Long;
vector<int>v;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j;
	string s;

	cin >> n >> s;
	v.resize(n);

	frn(i, n)
		cin >> v[i];

	int l = -1, r = -1, res = maxn;
	frn(i, n) {
		if (s.at(i) == 'R') {
			r = i;
		}
		else if (r != -1 && s.at(i) == 'L') {
			l = i;
			res = min(res, ((v[l] - v[r]) / 2));
			l = -1;
			r = -1;
		}
	}

	if (res == maxn) {
		cout << -1;
		return 0;
	}

	cout << res;

	//cin >> n;
	return 0;
}