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

const int maxn = 1e6 + 10;

int mem[maxn];
int v[maxn];

void DP(int p) {
	if(v[p] == 0)
		mem[p] = mem[p - 1];
	else {
		if (v[p] >= p)
			mem[p] = 1;
		else
			mem[p] = mem[p - v[p] - 1] + 1;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, i, j, mx = 0, mxv = 0;

	cin >> n;

	frn(i, n) {
		cin >> j;
		cin >> v[j];
	}

	if (v[0] > 0)
		mem[0] = 1;

	frN(i, maxn) {
		DP(i);
	}

	int r = max_element(mem, mem + maxn) - mem;

	cout << n - mem[r];

	//cin >> n;
	return 0;
}