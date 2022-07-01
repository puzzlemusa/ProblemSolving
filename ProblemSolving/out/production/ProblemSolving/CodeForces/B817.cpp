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

typedef long long Long;

const int maxn = 1e9 + 10;
vector<int>v;
map<Long, Long>mp;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n, i, j = 0, tot = 0, r = 1;

	cin >> n;

	frn(i, n) {
		Long a;
		cin >> a;
		mp[a]++;
	}

	auto it = mp.begin();

	frl(it, mp) {

		if (tot + it->second >= 3) {
			if (tot == 0)
				r = it->second * (it->second -1) * (it->second - 2) / 6;

			else if (tot == 1)
				r = it->second * (it->second - 1) / 2;

			else if (tot == 2)
				r = it->second;

			break;
		}

		tot += it->second;
	}

	cout << r;

	//cin >> n;
	return 0;
}