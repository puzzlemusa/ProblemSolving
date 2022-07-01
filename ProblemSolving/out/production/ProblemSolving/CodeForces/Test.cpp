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

typedef __int64 Long;

const int maxn = 300010;
vector<int>v;
queue<pair<int, int>>que;
set<int>st[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j = 1, q, c=0, t, a;

	cin >> n >> q;

	frN(i, q) {
		cin >> t >> a;
		
		if (t == 1) {
			que.push(make_pair(a, j));
			st[a].insert(j++);
			c++;
		}

		else if (t == 2) {
			c -= sz(st[a]);
			st[a].clear();
		}

		else if (t == 3) {
			while (!emt(que) && que.front().second <= a) {
				int p = que.front().first;
				int r = que.front().second;

				que.pop();

				if (st[p].find(r) != st[p].end()) {
					st[p].erase(st[p].find(r));
					c--;
				}
			}
		}

		cout << c << endl;
	}

	//cin >> n;
	return 0;
}