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
vector<int>w;
int n;
string s;


int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int i, j;

	cin >> n;

	while (n--) {
		cin >> s;
		string a = s.substr(4, s.size() - 4);
		int p = stoi(a);

		int tot = 0, t = 10;
		frv(i, 1, sz(a)) {
			tot += t;
			t *= 10;
		}

		while (p < 1989 + tot)
			p += t;

		cout << p <<endl;
	}

	//cin >> n;
	return 0;
}