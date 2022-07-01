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
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()

const int maxn = 300001;
typedef __int64 Long;
queue<pair<int, int>> qu;
set<int>v[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, q, t, val, tot = 0, i = 1;

	cin >> n >> q;

	while (q--) {
		cin >> t >> val;
		
		if (t == 1) {
			qu.push(make_pair(val, i));
			v[val].insert(i++);
			tot++;
		}
		else if (t == 2) {
			tot -= sz(v[val]);
			v[val].clear();
		}
		else {
			while (!emt(qu) && qu.front().second <= val) {
				int c = qu.front().first;
				int d = qu.front().second;
				if (v[c].find(d) != v[c].end()) {
					v[c].erase(d);
					tot--;
				}
				qu.pop();
			}
		}
		cout << tot << "\n";
	}

	//cin >> n;
	return 0;
}