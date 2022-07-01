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

const int maxn = 5e4 + 10;
int v[maxn], l[maxn], r[maxn], vis[maxn], mem[maxn];

void DP(int i) {
	int j, tot = 0, res = mem[i - 1];
	SET(vis, 0);
	int to = i;

	frr(j, i + 1) {
		int x = v[j];

		if (r[x] > i)
			break;

		to = min(to, l[x]);

		if (!vis[x]) {
			vis[x] = true;
			tot ^= x;
		}

		if (to == j) {
			res = max(res, mem[j - 1] + tot);
		}
	}

	mem[i] = res;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, i, j;

	cin >> n;

	frN(i, n) {
		cin >> v[i];
		if (!l[v[i]])
			l[v[i]] = i;

		r[v[i]] = i;
	}

	mem[0] = 0;
	frN(i, n) {
		DP(i);
	}

	cout << mem[n];

	//cin >> n;
	return 0;
}