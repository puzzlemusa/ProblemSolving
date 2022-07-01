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
#define pi (2*acos(0))
const int maxn = 1e9 + 10;
vector<int>v;
vector<pair<char, int>> mv[9][9];
bool vis[9][9];
int h[9][9];

vector<pair<char, int>> possibleMove(pair<char, int> S) {
	vector<pair<char, int>> v;

	int i, j, k;
	frn(i, 2)
	frn(j,2)
	frn(k, 2) {
		int a = S.first, b = S.second, c, d;
		if (i == 0) {
			c = 1;
			d = 2;
		}
		else {
			c = 2;
			d = 1;
		}
		
		if (j == 0)
			a += c;
		else
			a -= c;

		if (k == 0)
			b += d;
		else
			b -= d;

		if (a > 96 && a <= 104 && b > 0 && b <= 8)
			v.push_back(make_pair(a, b));
	}

	return v;
}

int BFS(pair<char, int> s, pair<char, int> d) {

	int j;
	queue <pair<char, int>>q;
	q.push(s);

	while (!emt(q)) {
		pair<char, int> a = q.front();
		q.pop();

		if (a == d) {
			return h[a.first - 96][a.second];
		}

		vis[a.first - 96][a.second] = true;

		frn(j, sz(mv[a.first - 96][a.second])) {
			pair<char, int> pr = mv[a.first - 96][a.second][j];
			if (!vis[pr.first - 96][pr.second]) {
				q.push(pr);
				h[pr.first - 96][pr.second] = h[a.first - 96][a.second] + 1;
			}
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
	int n, i, j, x1, y1, x2, y2;
	string a, b;

	frN(i, 8)
		frN(j, 8)
		mv[i][j] = possibleMove(make_pair(i+96, j));

	while (cin >> a >> b) {
		pair<char, int> S = make_pair(a.at(0), a.at(1) - 48);
		pair<char, int> D = make_pair(b.at(0), b.at(1) - 48);

		SET(vis, false);
		SET(h, 0);
		cout << "To get from " << a << " to " << b << " takes " << BFS(S, D) << " knight moves." << endl;
	}


	//cin >> n;
	return 0;
}