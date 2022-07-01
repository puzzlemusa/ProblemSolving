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

using namespace std;

const int maxn = 2e5 + 10;
typedef __int64 Long;
vector<int>moon;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n;
	cin >> n;
	moon.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> moon[i];
	}

	if (moon[n-1] == 0)
		cout << "UP";
	else if(moon[n - 1] ==15)
		cout << "DOWN";
	else if(n>1 && moon[n - 1] > moon[n - 2])
		cout << "UP";
	else if (n>1 && moon[n - 1] < moon[n - 2])
		cout << "DOWN";
	else
		cout << -1;

	//cin >> n;
	return 0;
}