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

const int maxn = 1e9 + 10;
typedef __int64 Long;
vector<int>v;
vector<int>x;
vector<int>y;

int M[1010][1010];

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, m, a, b, xm = 0, ym = 0, c = 0;

	cin >> n >> m;
	x.resize(n + 1);
	y.resize(m + 1);

	frN(i, n) {
		frN(j, m) {
			char ch;
			cin >> ch;

			M[i][j] = ch;

			if (ch == '*') {
				x[i]++;
				y[j]++;
				c++;
			}
		}
	}

	if (c == 0) {
		cout << "YES" << endl;
		cout << 1 << " " << 1;
		return 0;
	}

	frN(i, n) {
		frN(j, m) {
			if(M[i][j]=='*' && x[i] + y[j] == c+1) {
				cout << "YES" << endl;
				cout << i << " " << j;
				return 0;
			}
			else if (M[i][j] == '.' && x[i] + y[j] == c) {
				cout << "YES" << endl;
				cout << i << " " << j;
				return 0;
			}
		}
	}

	cout << "NO";
	return 0;

	//cin >> n;
	return 0;
}