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

typedef __int64 Long;
const Long maxn = 1e5 + 10;
const Long maxN = 1e18 + 10;
vector<Long>v(maxn);
string s[2][maxn];
Long mem[2][maxn];
Long n;

Long DP(Long t, Long p) {
	if (p == n)
		return 0;

	if (mem[t][p] != -1)
		return mem[t][p];

	Long r = maxN;

	if (t == 0) {
		if (s[0][p - 1] <= s[0][p])
			r = min(r, DP(0, p + 1));

		if (s[0][p - 1] <= s[1][p])
			r = min(r, (DP(1, p + 1) + v[p]));
	}
	else {
		if (s[1][p - 1] <= s[0][p])
			r = min(r, DP(0, p + 1));

		if (s[1][p - 1] <= s[1][p])
			r = min(r, (DP(1, p + 1) + v[p]));
	}
	

	return mem[t][p] = r;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	Long i, j;

	cin >> n;

	frn(i, n)
		cin >> v[i];

	frn(i, n) {
		cin >> s[0][i];
		s[1][i] = s[0][i];
		reverse(li(s[1][i]));
	}

	SET(mem, -1);

	mem[0][0] = 0;
	mem[1][0] = v[0];

	Long r1 = DP(0, 1);
	Long r2 = DP(1, 1) + v[0];

	Long r = min(r1, r2);

	if (r >= maxN)
		cout << -1;
	else
		cout << r;

	//cin >> n;
	return 0;
}