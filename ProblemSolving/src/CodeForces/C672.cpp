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

typedef __int64 Long;

const int maxn = 1e9 + 10;
vector<pair<int, int>>v;

long double distance(pair<int, int> a, pair<int, int> b) {
	long double x = a.first - b.first;
	long double y = a.second - b.second;
	return sqrt(x*x + y*y);
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, x, y;
	pair<int, int> a, b, c;
	long double tot = 0;

	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;

	cin >> n;
	v.resize(n);

	frn(i, n) {
		cin >> v[i].first >> v[i].second;
		tot += 2 * distance(v[i], c);
	}

	long double mxa = distance(c, v[0]) - distance(v[0], a);
	long double mxb = distance(c, v[0]) - distance(v[0], b);
	long double mx = max(mxa, mxb);

	frv(i, 1, n) {
		mx = max(mx, distance(c, v[i]) - distance(a, v[i]) + mxb);
		mx = max(mx, distance(c, v[i]) - distance(b, v[i]) + mxa);
		mxa = max(mxa, distance(c, v[i]) - distance(v[i], a));
		mxb = max(mxb, distance(c, v[i]) - distance(v[i], b));
		mx = max(mx, max(mxa, mxb));
	}

	cout << fixed << setprecision(12) << tot - mx;

	//cin >> n;
	return 0;
}