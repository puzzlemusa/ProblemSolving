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
#include <iomanip>

using namespace std;

typedef __int64 Long;
vector<Long> a;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n, n1, n2;
	string s;

	cin >> n >> n1 >> n2;
	a.resize(n);

	for (Long i = 0; i < n; i++) {
		cin >> a[i];
	}

	Long mn = min(n1, n2);
	Long mx = max(n1, n2);

	sort(a.begin(), a.end());

	int k = n - 1;
	Long totMin = 0;
	for (int i = 0; i < mn; i++) {
		totMin += a[k];
		k--;
	}
	double avgMin = totMin /(double) mn;
	if (mn == 0)
		avgMin = 0;
	
	Long totMax = 0;
	for (int i = 0; i < mx; i++) {
		totMax += a[k];
		k--;
	}
	double avgMax = totMax / (double)mx;
	if (mx == 0)
		avgMin = 0;

	std::cout << std::fixed;
	std::cout << std::setprecision(8);
	cout << avgMin + avgMax;

	//cin >> x1;

	return 0;
}