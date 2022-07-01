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
#define pi (2*acos(0))

typedef __int64 Long;

const int maxn = 1e9 + 10;
int x[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
string s[15];

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j;
	
	frn(i, 15) {
		cout << x[i] << endl;
		cin >> s[i];
	}
	
	bool prime = true;
	int c = 0;
	int d = 0;
	frn(i, 15) {
		if (s[i] == "yes") {
			prime = false;
			d = i;
			c++;
		}
	}

	if (prime)
		cout << "prime";

	else if (!prime && c == 1) {
		if ((x[d] * x[d]) > 100) {
			cout << "prime";
			return 0;
		}

		cout << (x[d] * x[d]) << endl;
		string s;
		cin >> s;
		if (s == "yes")
			cout << "composite";
		else
			cout << "prime";
	}

	else
		cout << "composite";

	//cin >> n;
	return 0;
}