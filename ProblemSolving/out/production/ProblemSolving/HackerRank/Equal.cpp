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

const int maxn = 1e9 + 10;
typedef __int64 Long;
vector<int>v;
vector<int>ch = {1,2,5};
unordered_map<int, int>mem;

int ChocolatesChanges(int n) {
	if (n == 0)
		return 0;
	if (n < 0)
		return maxn;

	if (mem.find(n) != mem.end())
		return mem[n];

	int mn = maxn;
	int i;
	frn(i, ch.size()) {
		int res = ChocolatesChanges(n - ch[i]) + 1;
		mn = min(mn, res);
	}

	return mem[n] = mn;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, t;

	ChocolatesChanges(10000);

	cin >> t;

	while (t--) {
		cin >> n;
		v.clear();
		v.resize(n);

		frn(i, n)
			cin >> v[i];

		sort(li(v));

		Long tot = 0, add = 0, dif = 0;
		bool a = false;
		frv(i, 1, n) {
			dif = (v[i] + add) - v[i - 1];
			if (dif> 0) {
				tot += mem[dif];
				if(a)
					v[i] += add;
				add += dif;
				a = true;
			}
		}

		cout << tot << "\n";

	}

	//cin >> n;
	return 0;
}