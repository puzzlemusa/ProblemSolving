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
	Long n, a, b, c;

	cin >> n >> a >> b >> c;

	Long needToBuy = (4 - n%4);

	if (needToBuy == 4) {
		cout << 0;
		return 0;
	}

	Long tot = 0;
	if (needToBuy == 1) {
		Long withA = a;
		Long withB = b + c;
		Long withC = c * 3;
		tot = min(min(withA, withB), withC);
	}
	else if (needToBuy == 2) {
		Long withA = a * 2;
		Long withB = b;
		Long withC = c * 2;
		tot = min(min(withA, withB), withC);
	}
	else if (needToBuy == 3) {
		Long withA = a * 3;
		Long withB = a + b;
		Long withC = c;
		tot = min(min(withA, withB), withC);
	}

	cout << tot;
	//cin >> n;

	return 0;
}