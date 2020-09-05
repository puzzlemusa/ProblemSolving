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

typedef long long Long;

const int maxn = 2147483647;
vector<int>v;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string s1 = s + s;
        s1 = s1.substr(1, sz(s1)-1);
        s1 = s1.substr(0, sz(s1)-1);

        size_t found = s1.find(s);

        if(found != std::string::npos)
            return true;
        else
            return false;
    }
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w", stdout);
#endif
	Solution sol;
	vector<int>v = {1,5,9,1,5,9};
	cout << sol.repeatedSubstringPattern("abab");


	//cin >> n;
	return 0;
}