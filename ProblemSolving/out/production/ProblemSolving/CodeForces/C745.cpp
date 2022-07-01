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
const int maxn = 1e3 + 10;
vector<int>v;
vector<int>vn;
vector<int>ve;
vector<bool>vis;
vector<int>ad[maxn];

Long calc(Long n) {
	if (n <= 0)
		return 0;

	return n*(n + 1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	Long n, i, j, m, k;

	cin >> n >> m >> k;
	v.resize(k + 1);
	vn.resize(k + 1);
	ve.resize(k + 1);
	vis.resize(n + 1);

	frN(i, k)
		cin >> v[i];

	frn(i, m) {
		Long a, b;
		cin >> a >> b;
		ad[a].push_back(b);
		ad[b].push_back(a);
	}

	frN(i, k) {
		stack<Long> st;
		st.push(v[i]);
		Long x = 0, y = 0;
		while (!emt(st)) {
			Long a = st.top();
			st.pop();
			if (!vis[a]) {
				x++;
				vis[a] = true;
				Long j;
				frn(j, sz(ad[a])) {
					if (!vis[ad[a][j]]) {
						st.push(ad[a][j]);
						y++;
					}
				}
			}
		}

		ve[i] = y;
		vn[i] = x;
	}
	int mxG = max_element(li(vn)) - vn.begin();
	Long tot = 0;
	Long rn = n;
	frN(i, k) {
		if (mxG != i) {
			tot += calc(vn[i] - 1) - ve[i];
			rn -= vn[i];
			m -= ve[i];
		}
	}

	tot += calc(rn - 1);
	tot -= m;

	cout << tot;

	//cin >> n;
	return 0;
}