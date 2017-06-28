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

const int maxn = 200010;
int v[maxn][2];

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n, i, j, tot = 0, c;
	string a, b;

	cin >> a >> b;

	c = b.at(0) - '0';
	v[0][c]++;
	frv(i, 1, sz(b)) {
		c = b.at(i) - '0';
		
		v[i][0] = v[i - 1][0];
		v[i][1] = v[i - 1][1];

		v[i][c]++;
	}

	frn(i, sz(a)) {
		c = abs(a.at(i) - '1');

		j = sz(b) - (sz(a) - i);

		if (i > 0)
			tot += v[j][c] - v[i-1][c];
		else
			tot += v[j][c];
	}

	cout << tot;

	//cin >> n;
	return 0;
}