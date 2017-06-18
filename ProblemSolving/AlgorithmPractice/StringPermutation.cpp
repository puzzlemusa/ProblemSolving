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
#define frr(i,n) for(i=n-1;i>=0;i--)
#define frv(i,a,n) for(i=a;i<n;i++)
#define frl(i,v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v,a) memset(v,a,sizeof(v))

typedef __int64 Long;
const int maxn = 1e9 + 10;
vector<int>v;

void swap(string &s, int x, int y)
{
	char temp;
	temp = s.at(x);
	s.at(x) = s.at(y);
	s.at(y) = temp;
}

void permutation(string s, int start, int length) {
	int i;

	if (start == length)
		cout << s << endl;
	else {
		frv(i, start, length + 1) {
			swap(s, start, i);
			permutation(s, start + 1, length);
			//swap(ch + start, ch + i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j;
	string s;

	cin >> s;

	permutation(s, 0, sz(s) - 1);

	//cin >> n;
	return 0;
}