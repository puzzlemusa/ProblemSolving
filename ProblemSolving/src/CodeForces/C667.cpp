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

vector<int>v;
string s;
int n;
map<pair<int, string>, bool> mem;
set<string> st;

bool DP(int p, string s1) {
	if (p > n)
		return false;
	else if (p == n)
		return true;

	if (mem.find(make_pair(p, s1)) != mem.end())
		return mem[make_pair(p, s1)];

	bool r = false;

	string s2 = s.substr(p, 2);
	if (s2 != s1 && DP(p + 2, s2)) {
		r = true;
		st.insert(s2);
	}
		
	s2 = s.substr(p, 3);
	if (s2 != s1 && DP(p + 3, s2)) {
		r = true;
		st.insert(s2);
	}

	return mem[make_pair(p, s1)] = r;
		
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int i, j;
	
	cin >> s;
	n = sz(s);

	frv(i, 5, n)
		DP(i, "");

	cout << sz(st) << endl;
	auto it = st.begin();
	frl(it, st) {
		cout << *it << endl;
	}

	//cin >> n;
	return 0;
}