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

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, rCount = 0, bCount = 0;
	string s;
	char fc;
	cin >> n >> s;

	int bError = 0, rError = 0;
	int minRErr, minBErr;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0 && s.at(i) != 'r')
			rError++;
		else if (i % 2 == 1 && s.at(i) != 'b')
			bError++;
	}

	minRErr = max(rError, bError);

	bError = 0, rError = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0 && s.at(i) != 'b')
			bError++;
		else if (i % 2 == 1 && s.at(i) != 'r')
			rError++;
	}

	minBErr = max(rError, bError);

	cout << min(minRErr, minBErr);

	//cin >> n;
	return 0;
}