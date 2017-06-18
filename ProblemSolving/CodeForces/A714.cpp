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

const int maxn = 2e5 + 10;
typedef __int64 Long;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long l1, r1, l2, r2, k;
	Long maxS, maxE, minS, minE;
	Long result = 0;
	cin >> l1 >> r1 >> l2 >> r2 >> k;

	maxS = max(l1, l2);
	minE = min(r1, r2);

	if (minE >= maxS) {
		result = (minE - maxS) + 1;
		if (k >= maxS && k <= minE)
			result--;
	}

	cout << result;

	//cin >> n;
	return 0;
}