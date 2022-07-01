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
map<Long, Long> memory;

Long gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n;
	
	cin >> n;

	Long currentScreen = 2;
	for (Long i = 1; i <= n; i++) {
		Long lcm = (i*(i + 1)) / gcd(i, (i + 1));
		Long r = (lcm/i)*(lcm);
		cout << r - (currentScreen/i) << "\n";
		currentScreen = lcm;
	}

	//cin >> n;
	return 0;
}