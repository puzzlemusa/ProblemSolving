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
vector<Long> info;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n, c;

	cin >> n >> c;
	info.resize(n);

	for (Long i = 0; i < n; i++) {
		cin >> info[i];
	}

	Long tot = 1;
	for (Long i = 1; i < n; i++) {
		if (info[i] - info[i - 1] > c)
			tot = 1;
		else {
			tot++;
		}
	}

	cout<< tot;

	//cin >> n;
	return 0;
}