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
vector<int>v[2];
vector<pair<int, int>> mp;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	Long n, i, k;

	cin >> n >> k;
	v[0].resize(n);
	v[1].resize(n);
	mp.resize(n);

	frn(i, n) {
		cin >> v[0][i];
	}
	frn(i, n) {
		cin >> v[1][i];
		mp[i] = make_pair(v[0][i], v[1][i]);
	}
	std::sort(mp.begin(), mp.end(), [](auto &left, auto &right) {
		return left.first - left.second < right.first - right.second;
	});

	int r = 0, tot = 0;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if (it->first - it->second <= 0) {
			tot += it->first;
			r++;
		}
		else if (r < k) {
			tot += it->first;
			r++;
		}
		else {
			tot += it->second;
		}
	}

	cout << tot;
	//cin >> n;
	return 0;
}