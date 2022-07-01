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

typedef long long Long;
const int maxn = 1e9 + 10;
vector<Long>v;
Long k;
Long mem[101][100010];


Long DP(Long l, Long c) {
	if (c == k)
		return 0;

	if (mem[l][c] != -1)
		return mem[l][c];

	Long r = 0;
	
	r = max(r, abs(l - 1) + DP(1, c + 1));
	r = max(r, abs(l - v[c]) + DP(v[c], c + 1));
	

	return mem[l][c] = r;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	Long n, i, j;

	cin >> n;

	while (n--) {
		cin >> k;
		v.clear();
		v.resize(k);
		frn(i, k)
			cin >> v[i];

		SET(mem, -1);

		Long r = 0;
		
		r = max(r,  DP(1, 1));
		r = max(r,  DP(v[0], 1));

		cout << r << endl;
	}

	//cin >> n;
	return 0;
}