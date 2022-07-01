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
	int n, k;
	string s;

	cin >> n >> k;
	cin >> s;

	int G = -1, T = -1;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'G')
			G = i;
		else if (s.at(i) == 'T')
			T = i;
	}
	int mn = min(G, T);
	int mx = max(G, T);

	for (int i = mn; i < s.length(); i += k) {
		if (i == mx) {
			cout << "YES";
			return 0;
		}
		else if (s.at(i) == '#') {
			cout << "NO";
			return 0;
		}
	}
	cout << "NO";

	//cin >> x1;

	return 0;
}