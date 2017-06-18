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
#define SET(v,a) memset(v,a,sz(v))

const int maxn = 1e9 + 10;
typedef __int64 Long;
vector<int>v;


int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, k, mid;

	cin >> n;
	v.resize(n);

	frn(i, n)
		cin >> v[i];

	cin >> k;
	sort(li(v));

	while (k--) {
		int f;
		cin >> f;
		int beg = 1, end = n;
		while (beg < end) {
			mid = (beg + end) / 2;
			if (f >= v[mid])
				beg = mid + 1;
			else
				end = mid;
		}
		if (v[0] > f)
			cout << 0 << endl;
		else
			cout << beg << endl;
	}
	//cin >> n;
	return 0;
}