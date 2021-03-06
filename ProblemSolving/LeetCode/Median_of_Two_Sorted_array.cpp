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
vector<int>v, u;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
		int n = sz(A);
		int m = sz(B);
		
		if (n > m)
			return findMedianSortedArrays(B, A);

		if (n == 0)
			return ((double)B[(m - 1) / 2] + (double)B[m / 2]) / 2;

		int k = (n + m - 1) / 2;
		int l = 0, r = min(k, n);
		while (l < r) {
			int midA = (l + r) / 2;
			int midB = k - midA;
			if (A[midA] < B[midB])
				l = midA + 1;
			else
				r = midA;
		}

		int a = max(l > 0 ? A[l - 1] : INT_MIN, k - l >= 0 ? B[k - l] : INT_MIN);
		if (((n + m) & 1) == 1)
			return (double)a;

		int b = min(l < n ? A[l] : INT_MAX, k - l + 1 < m ? B[k - l + 1] : INT_MAX);
		return (a + b) / 2.0;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Solution sol;
	int n, i, j, m;

	cin >> n >> m;

	frn(i, n) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	frn(i, m) {
		int a;
		cin >> a;
		u.push_back(a);
	}

	cout << sol.findMedianSortedArrays(v, u);

	//cin >> n;
	return 0;
}