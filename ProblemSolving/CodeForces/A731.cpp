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
	string s;
	cin >> s;

	int tot = 0;
	int pointer = 1;
	for (int i = 0; i < s.length(); i++) {
		int d = s.at(i) % 96;
		int dis = abs(pointer - d);
		if (dis > 13)
			dis = 26 - dis;

		tot += dis;
		pointer = d;
	}
	cout << tot;

	//cin >> n;
	return 0;
}