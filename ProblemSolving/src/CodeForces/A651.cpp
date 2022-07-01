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

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, i, j = 0, a, b;

	cin >> a >> b;

	if (a == 1 && b == 1) {
		cout << 0;
		return 0;
	}

	if (a > b)
		i = 2;
	else
		i = 1;

	while (a > 0 && b > 0) {
		if (i == 1) {
			a++;
			b -= 2;
		}
		else {
			a -= 2;
			b++;
		}

		if (a <= 2)
			i = 1;
		else if (b <= 2)
			i = 2;

		j++;
	}

	cout << j;

	//cin >> n;
	return 0;
}