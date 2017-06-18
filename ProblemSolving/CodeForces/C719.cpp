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
	Long n, t;
	string s;
	cin >> n >> t >>s;
	
	n--;
	for (Long i = 0; i < t; i++, n--) {
		if (s.at(n) == '.') {
			n++;
			break;
		}
		else if (s.at(n) == 48) {
			s.erase(n, 1);
		}
		else if(s.at(n) >= 53 ) {
			if (s.at(n - 1) != '.') {
				s.at(n - 1)++;
				s.erase(n, s.size() - i);
			}
			else {
				s.at(n - 2)++;
				s.erase(n-1, s.size() - (n-1));
			}
		}
	}
	
	cout << s;
	//cin >> n;
	return 0;
}