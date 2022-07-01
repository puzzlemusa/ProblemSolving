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

using namespace std;

const int maxn = 2e5 + 10;
typedef __int64 Long;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, m, mn = maxn;
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		mn = min(mn, (b - a + 1));
	}

	cout << mn <<"\n";
	int k = 0;
	for (int i = 0; i < n; i++, k++) {
		if (k == mn)
			k = 0;
		if (i < n - 1) {
			cout << k << " ";
		}
		else
			cout << k;
	}
	
	//cin >> n;
	return 0;
}