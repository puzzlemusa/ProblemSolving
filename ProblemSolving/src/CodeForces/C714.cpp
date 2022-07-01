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
unordered_map<string, Long>mp;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long t;
	cin >> t;

	for (Long i = 0; i < t; i++) {
		char ch;
		string s, deft = "0000000000000000000";
		cin >> ch >> s;
		if (ch == '+') {
			string a = deft;
			a.erase(19 - s.length() + 1, s.length());
			for (Long i = 0; i < s.size(); i++) {
				int v = s[i];
				s[i] = (v % 2) + 48;
			}
			a += s;
			mp[a]++;
		}
		else if (ch == '-') {
			string a = deft;
			a.erase(19 - s.length() + 1, s.length());
			for (Long i = 0; i < s.size(); i++) {
				int v = s[i];
				s[i] = (v % 2) + 48;
			}
			a += s;
			mp[a]--;
		}
		else if (ch == '?') {
			string a = deft;
			a.erase(19 - s.length() + 1, s.length());
			a += s;

			cout << mp[a] << "\n";
		}
	}

	//cin >> n;
	return 0;
}