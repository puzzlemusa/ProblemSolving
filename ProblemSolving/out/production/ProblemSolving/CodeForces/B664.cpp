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
#define SET(v,a) memset(v,a,sz(v))

const int maxn = 1e9 + 10;
typedef __int64 Long;
vector<int>v;
vector<int>w;
int n;
string s;

void print() {
	cout << v[0];
	int i, j = 1, k =0;
	frn(i, sz(s)) {
		if (s.at(i) == '+') {
			cout << " + " << v[j++];
		}

		else if (s.at(i) == '-') {
			cout << " - " << w[k++];
		}

		else if (s.at(i) == '=')
		{
			cout << " = " << n;
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
	int i, j,p=1,q=0;
	std::getline(std::cin, s);

	frn(i, sz(s)) {
		if (s.at(i)=='+')
			p++;

		else if (s.at(i)=='-')
			q++;

		else if (s.at(i)=='=')
		{
			string s1 = s.substr(i + 1, sz(s) - (i + 1));
			n = stoi(s1);
		}
	}

	if (p - n*q <= n && n <= p*n - q) {
		cout << "Possible" << endl;
		v.resize(p, 1);
		w.resize(q, 1);

		int r = (p - q) - n;

		if (r < 0) {
			for (int k = 0; k < p && r; k++) {
				int add = min(n - 1, -r);
				v[k] += add;
				r += add;
			}
		}
		else {
			for (int k = 0; k < q && r; k++) {
				int add = min(n - 1, r);
				w[k] += add;
				r -= add;
			}
		}
		
		print();
	}
	else {
		cout << "Impossible";
	}
	//cin >> n;
	return 0;
}