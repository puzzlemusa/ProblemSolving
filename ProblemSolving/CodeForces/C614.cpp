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

const Long maxn = 1e18 + 10;
vector<int>v;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, i, j, a, b;
	pair<int, int> P;
	double mx = 0, mn = maxn, d;

	cin >> n >> P.first >> P.second;

	frn(i, n) {
		cin >> a >> b;
		d = sqrt(((a - P.first) * (a - P.first)) + ((b - P.second) * (b - P.second)));

		mx = max(mx, d);
		mn = min(mn, d);
	}

	double r = (pi * mx * mx) - (pi * mn * mn);

	cout << fixed << setprecision(14) << r;

	//cin >> n;
	return 0;
}