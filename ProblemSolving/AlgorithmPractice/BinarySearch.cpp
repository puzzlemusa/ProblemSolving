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

typedef __int64 Long;

const int maxn = 1e9 + 10;
vector<int>v;
int n;

int lowerBound(int a) {
	int left = 0, right = n - 1, mid;

	if (a > v[right])
		return n;

	while (left < right) {
		mid = (left + right) / 2;

		if (a <= v[mid])
			right = mid;
		else
			left = mid + 1;
	}

	return left;
}

int upperBound(int a) {
	int left = 1, right = n, mid;

	if (a < v[0])
		return 0;

	while (left < right) {
		mid = (left + right) / 2;

		if (a >= v[mid])
			left = mid + 1;
		else
			right = mid;
	}

	return left;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int i, j, a;

	cin >> n;
	v.resize(n);

	frn(i, n)
		cin >> v[i];

	sort(li(v));

	cin >> a;

	cout << "Lower bound: " << lowerBound(a) << " original: " << lower_bound(li(v), a) - v.begin() <<  endl;
	cout << "Upper bound: " << upperBound(a) << " original: " << upper_bound(li(v), a) - v.begin() << endl;


	//cin >> n;
	return 0;
}