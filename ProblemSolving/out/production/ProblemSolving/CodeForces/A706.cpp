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
	Long x, y, n;
	double mn = maxn;
	cin >> x >> y >> n;


	for (Long i = 0; i < n; i++) {
		Long x1, y1, v;
		cin >> x1 >> y1 >> v;
		double distance = sqrt(((x1 - x)*(x1 - x)) + ((y1 - y)*(y1 - y)));
		distance /= v;
		mn = min(mn, distance);
	}

	std::cout << std::fixed;
	std::cout << std::setprecision(16);
	cout << mn;

	//cin >> n;
	return 0;
}