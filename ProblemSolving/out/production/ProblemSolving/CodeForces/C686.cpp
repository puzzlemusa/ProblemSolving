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

int digit(int n) {
	n--;
	if (n == 0)
		return 1;
	int c = 0;
	while (n) {
		n /= 7;
		c++;
	}
	return c;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, m, d1, d2, r = 0,a,b,k;

	cin >> n >> m;

	d1 = digit(n);
	d2 = digit(m);

	if (d1 + d2 <= 7) {
		vector<int> v;
		frn(i, n) {
			v.clear();
			v.resize(7, 0);
			a = i;
			k = 0;
			while (k++ < d1) {
				v[a % 7]++;
				a /= 7;
			}
			if (*max_element(li(v)) > 1)
				continue;

			frn(j, m) {
				vector<int> u = v;
				b = j;
				k = 0;
				while (k++ < d2) {
					u[b % 7]++;
					b /= 7;
				}
				if (*max_element(li(u)) <= 1)
					r++;
			}
		}
	}

	cout << r;

	//cin >> n;
	return 0;
}