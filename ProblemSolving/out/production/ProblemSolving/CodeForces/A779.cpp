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

const int maxn = 1e9 + 10;
typedef __int64 Long;
unordered_map<int, int>mp;
unordered_map<int, int>st[2];

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i;

	cin >> n;

	frn(i, n) {
		int b;
		cin >> b;
		mp[b]++;
		st[0][b]++;
	}
	frn(i, n) {
		int b;
		cin >> b;
		mp[b]++;
		st[1][b]++;
	}

	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->second % 2 == 1) {
			cout << -1;
			return 0;
		}
	}

	int tot = 0;
	for (auto it = st[0].begin(); it != st[0].end(); ++it) {
		int r = st[1][it->first];

		if (it->second > r) {
			tot += (it->second - r) / 2;
		}
	}

	cout << tot;

	//cin >> n;
	return 0;
}