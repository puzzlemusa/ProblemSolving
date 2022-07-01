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
const int maxn = 1e5 + 10;
vector<int>v;
vector<bool>vi;
vector<int>ad[maxn];
set<int> x;
set<int> y;
bool e = false;

void DFS(int a) {
	vi[a] = true;

	int j;
	frn(j, sz(ad[a])) {
		if (x.find(a) != x.end()) {
			if (x.find(ad[a][j]) != x.end()) {
				e = true;
				return;
			}
			else
				y.insert(ad[a][j]);
		}

		else if (y.find(a) != y.end()) {
			if (y.find(ad[a][j]) != y.end()) {
				e = true;
				return;
			}
			else
				x.insert(ad[a][j]);
		}
		if (!vi[ad[a][j]]) {	
			DFS(ad[a][j]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j , m;

	cin >> n >> m;
	vi.resize(n + 1);

	frn(i, m) {
		int a, b;
		cin >> a >> b;
		ad[a].push_back(b);
		ad[b].push_back(a);
	}

	frN(i, n) {
		if (ad[i].size() > 0 && !vi[i]) {
			e = false;
			x.insert(i);
			DFS(i);
			if (e) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << x.size() << endl;
	auto it = x.begin();
	frl(it, x)
		cout << *it << " ";
	

	cout << endl << y.size() << endl;
	auto jt = y.begin();
	frl(jt, y)
		cout << *jt << " ";

	//cin >> n;
	return 0;
}