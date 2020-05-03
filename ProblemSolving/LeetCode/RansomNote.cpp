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

const int maxn = 2147483647;
vector<int>v;


class Solution {
public:
	bool canConstruct(string J, string S) {
		map<char, int> r;
		map<char, int> m;
		map<char, int>::iterator it_m;
		map<char, int>::iterator it_r;

		int i = 0;
		int c = 0;
		frn(i, sz(J)) {
			r[J[i]]++;
		}

		i = 0;
		frn(i, sz(S)) {
			m[S[i]]++;
		}

		for (it_r = r.begin(); it_r != r.end(); ++it_r) {
			it_m = m.find(it_r->first);
			if (it_m != m.end()) {
				if (it_r->second > it_m->second)
					return false;
			}
			else return false;
		}

		return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w", stdout);
#endif

	Solution sol;
	string J, S;
	cin >> J >> S;
	cout << sol.numJewelsInStones(J, S);

	//cin >> n;
	return 0;
}