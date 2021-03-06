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
const int maxn = 1e9 + 10;
vector<Long>v;

Long GCD(Long a, Long b) {
	if (b == 0)
		return a;

	return GCD(b, a%b);
}

Long LCM(Long a, Long b) {
	return (a*b) / GCD(a, b);
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	Long n, i, j, tot = 1;

	cin >> n;
	v.resize(n + 1);

	frN(i, n)
		cin >> v[i];

	frN(i, n) {
		Long c = v[i];
		frN(j, n) {
			if (c == i)
				break;

			c = v[c];
		}

		if (j > n) {
			cout << -1;
			return 0;
		}

		j = j % 2 == 0 ? j / 2 : j;

		tot = LCM(tot, j);
	}

	cout << tot;

	//cin >> n;
	return 0;
}