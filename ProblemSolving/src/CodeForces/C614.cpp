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
vector<pair<double, double>>v;

double distance(double a, double b, double c, double d) {
	return sqrt((a - c) * (a - c) + (d - b) * (d - b));
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, i, j;
	pair<double, double> P;
	double mx = 0, mn = maxn, d;

	cin >> n >> P.first >> P.second;
	v.resize(n + 1);

	frn(i, n) {
		cin >> v[i].first >> v[i].second;
		d = distance(P.first, P.second, v[i].first, v[i].second);

		mx = max(mx, d);
	}
	v[n] = v[0];

	frn(i, n) {
		double ds = distance(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
		double dx = distance(P.first, P.second, v[i].first, v[i].second);
		double dx1 = distance(P.first, P.second, v[i+1].first, v[i+1].second);
		double ara = fabs(((v[i].first - P.first) * (v[i + 1].second - P.second)) - ((v[i + 1].first - P.first) * (v[i].second - P.second)));
		double h = ara / ds;

		if ((dx * dx + ds * ds < dx1 * dx1) || (dx1 * dx1 + ds * ds < dx * dx))
			mn = min(mn, dx);
		else
			mn = min(mn, h);
	}

	double r = (pi * mx * mx) - (pi * mn * mn);

	cout << fixed << setprecision(14) << r;

	//cin >> n;
	return 0;
}