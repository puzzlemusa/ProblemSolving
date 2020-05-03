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
	int myAtoi(string str) {
		int i;
		bool num_found = false;
		bool sign_found = false;
		string result = "";
		frn(i, str.length())
		{
			char c = str[i];
			if(int(c == 43) || int(c) == 43)
			{
				if (sign_found)
					return 0;
				else
				{
					result = result + c;
					sign_found = true;
				}
			}
			else if(int(c) >= 48 && int(c) <= 57){
				result = result + c;
				num_found = true;
			}
			else if (int(c) == 32) {
				
			}
			else
			{
				if (num_found)
					break;
				else 
					return 0;
			}
		}

		Long converted_result = std::stoll(result);
		int final_result = 0;
		if (converted_result > maxn)
			final_result = maxn;
		else if (converted_result < (1 - maxn - 1))
			final_result = 1 - maxn - 1;

		return final_result;
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
	string s;
	getline(cin, s);
	cout << sol.myAtoi(s);

	//cin >> n;
	return 0;
}