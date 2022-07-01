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
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	string s;

	cin >> s;
	
	int tot = 0;
	for (int i = 0; i < s.length(); i++) {
		string s1 = s.substr(0, i);
		string s2 = s.substr(i + 1, s.length() - 1);
		string ns = s2 + s1;

		if (mp.find(ns) == mp.end()) {
			tot++;
			mp[ns] = i;
		}
	}
	cout << tot;
	//cin >> s;
	//printf("\n");
	return 0;
}