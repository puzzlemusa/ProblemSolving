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
map<string, int> mp;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n;
	cin >> n;

	if (n == 0)	{
		cout << 1;
		return 0;
	}
	else if (n % 4 == 0) {
		cout << 6;
	}
	else if (n % 4 == 1) {
		cout << 8;
	}
	else if (n % 4 == 2) {
		cout << 4;
	}
	else if (n % 4 == 3) {
		cout << 2;
	}
	//cin >> n;
	//printf("\n");
	return 0;
}