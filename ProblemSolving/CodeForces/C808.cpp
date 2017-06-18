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
vector<int>c;
vector<pair<int, int>>pr;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, w, avs= 0;

	cin >> n >> w;
	v.resize(n);
	c.resize(n);
	pr.resize(n);

	j = w;

	frn(i, n) {
		cin >> v[i];
		pr[i] = pair<int, int>(v[i], i);
		int val = v[i] % 2 == 0 ? v[i] / 2 : v[i] / 2 + 1;
		avs += val;
		c[i] = val;
		w -= val;
	}

	if (avs > j) {
		cout << -1;
		return 0;
	}
	
	sort(li(pr));

	if (w > 0) {
		frr(i, n) {
			int j = pr[i].second;
			if (v[j] - c[j] < w) {
				int diff = v[j] - c[j];
				c[j] += diff;
				w -= diff;
			}
			else {
				c[j] += w;
				w -= w;
			}

			if (w == 0)
				break;
		}
	}

	frn(i, n)
		cout << c[i] << " ";

	//cin >> n;
	return 0;
}