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
const int maxn = 1e9 + 10;
vector<int>v;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, k;
	string s, x ,y ,m, o;

	cin >> s;
	x = s.at(0);
	bool f = false;
	frn(i, sz(s)) {
		if (s.at(i) == '.')
			f = true;

		else if (s.at(i) == 'e')
			break;

		else if (f)
			y += s.at(i);
	}

	m = s.substr(i+1, (sz(s)-1) - i);
	n = stoi(m);

	o = x;

	f = false;
	if (n >= sz(y)) {
		o += y;
		n -= sz(y);

		frn(i,n)
			o += '0';
	}
	else {
		o += y.substr(0, n);
		o += '.';
		f = true;
		o += y.substr(n, y.size() - n);
	}

	if (f) {
		frr(i, sz(o)) {
			if (o.at(i) == '0') {
				o.erase(i, 1);
			}
			else
				break;
		}
	}
	else {
		if (o.at(0) == '0')
			o.erase(0, 1);
	}

	if (o.at(sz(o)-1) == '.')
		o.erase(sz(o) - 1, 1);

	cout << o;

	//cin >> n;
	return 0;
}