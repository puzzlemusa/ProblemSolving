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

const int maxn = 1e9 + 10;
typedef __int64 Long;
vector<int>v;
int n;
int mem[3][105];

#define REST_YESTERDAY 0
#define GYM_YESTERDAY 1
#define CONTEST_YESTERDAY 2

#define REST_TODAY 0
#define GYM_TODAY 1
#define CONTEST_TODAY 2

int DP(int d, int t) {
	if (d == n)
		return 0;

	if (mem[t][d] != -1)
		return mem[t][d];

	int r = DP(d + 1, REST_TODAY) + 1;

	if (v[d] == 1) {
		if (t != CONTEST_YESTERDAY)
		{
			r = min(r, DP(d + 1, CONTEST_TODAY));
		}
	}

	if (v[d] == 2) {
		if (t != GYM_YESTERDAY) {
			r = min(r, DP(d + 1, GYM_TODAY));
		}
	}

	if (v[d] == 3) {
		if (t == GYM_YESTERDAY) {
			r = min(r, DP(d + 1, CONTEST_TODAY));
		}
		if (t == CONTEST_YESTERDAY) {
			r = min(r, DP(d + 1, GYM_TODAY));
		}
		if (t == REST_YESTERDAY) {
			r = min(r, DP(d + 1, CONTEST_TODAY));
			r = min(r, DP(d + 1, GYM_TODAY));
		}
	}

	return mem[t][d] = r;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int i, j;

	cin >> n;
	v.resize(n);

	frn(i, n)
		cin >> v[i];

	SET(mem, -1);

	cout << DP(0, 0);

	//cin >> n;

	return 0;
}