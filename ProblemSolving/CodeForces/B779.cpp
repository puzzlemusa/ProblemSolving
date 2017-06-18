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
unordered_map<int, int>mp;
unordered_map<int, int>st[2];
stack<Long> pos;

void findNon(Long n) {
	string s = to_string(n);
	Long i;
	frn(i, s.size()) {
		if (s.at(i) != '0')
			pos.push(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	Long n, i, k;

	cin >> n >> k;

	findNon(n);

	Long tot = 0;
	string s = to_string(n);
	while (!pos.empty() && s.size() > k) {
		s = to_string(n);
		Long e = pow(10, k);
		if (n % e == 0)
			break;
		else {
			Long charPos = pos.top();
			pos.pop();
			s.erase(charPos, 1);
			n = stoi(s);
			tot++;
		}
	}

	if (s.size() <= k) {
		Long a = s.find('0');
		if (a != -1)
			tot += s.size() - 1;
		else
			tot += s.size();
	}

	cout << tot;

	//cin >> n;
	return 0;
}