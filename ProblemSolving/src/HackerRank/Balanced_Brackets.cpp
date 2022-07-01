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

#define frn(i,n) for(i=0;i<n;i++)
#define frN(i,n) for(i=1;i<=n;i++)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()

const int maxn = 1e9 + 10;
typedef __int64 Long;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i;

	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		stack<char> st;
		bool c = false;
		frn(i, s.size()) {
			if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
				st.push(s.at(i));

			else {
				if (st.empty()) {
					cout << "NO" << "\n";
					c = true;
					break;
				}
				else {
					char ch = st.top();
					st.pop();
					if (s.at(i) == ')' && ch != '(') {
						cout << "NO" << "\n";
						c = true;
						break;
					}
					else if (s.at(i) == '}' && ch != '{') {
						cout << "NO" << "\n";
						c = true;
						break;
					}
					else if (s.at(i) == ']' && ch != '[') {
						cout << "NO" << "\n";
						c = true;
						break;
					}
				}
			}
		}
		if (i == sz(s) && emt(st)) {
			cout << "YES" << "\n";
			c = true;
		}

		if(!c)
			cout << "NO" << "\n";
			
	}

	//cin >> n;
	return 0;
}