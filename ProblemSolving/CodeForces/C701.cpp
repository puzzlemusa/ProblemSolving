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
#define SET(v,a) memset(v,a,sz(v))

const int maxn = 1e9 + 10;
typedef __int64 Long;
vector<int>v;
set<char> st;
multiset<char>mst;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j = 0, m;
	string s;

	cin >> n >> s;

	frn(i, sz(s))
		st.insert(s.at(i));

	m = sz(st);
	st.clear();

	i = 0;
	int tot = maxn;
	while(i < n) {
		while (i < n && sz(st) < m) {
			mst.insert(s.at(i));
			st.insert(s.at(i));
			i++;
		}

		while (j < i && sz(st) == m) {
			tot = min(tot, sz(mst));
			mst.erase(mst.find(s[j]));
			if (mst.find(s.at(j)) == mst.end())
				st.erase(s[j]);
			j++;
		}
	}

	cout << tot;

	//cin >> n;
	return 0;
}