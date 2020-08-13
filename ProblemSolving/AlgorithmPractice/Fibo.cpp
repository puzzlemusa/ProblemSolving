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
typedef long long Long;
vector<int>v;
unordered_map<int, int>mp;
int c = 0;

int fiboNthWithMemo(int n) {
	if (mp.find(n) != mp.end())
		return mp[n];
	c++;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return mp[n] = fiboNthWithMemo(n - 1) + fiboNthWithMemo(n - 2);
}

int fiboShowTillNthWithMemo(int n) {
	if (mp.find(n) != mp.end())
		return mp[n];
	c++;
	if (n == 0) {
		return 0;
		cout << n << " ";
	}
	if (n == 1) {
		return 1;
		cout << n << " ";
	}

	int r = fiboShowTillNthWithMemo(n - 1) + fiboShowTillNthWithMemo(n - 2);
	cout << r << " ";
	return mp[n] = r;
}

int fiboNth(int n) {
	c++;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fiboNth(n - 1) + fiboNth(n - 2);
}

pair<int, int> fiboNthLinearTimeWithoutMemo(int n) {
	c++;
	if (n == 2)
		return make_pair(1, 1);

	pair<int,int> r = fiboNthLinearTimeWithoutMemo(n - 1);

	return make_pair(r.first + r.second, r.first);
}

int fiboWithLoop(int n){
    int i;
    int a=0, b=1, tot;
    frn(i,n){
        c++;
        tot = a + b;
        a = b;
        b = tot;
    }
    return a;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j;

	n = 5;

	cout << "Without memorization, " << n <<"th value " << fiboNth(n);
	cout<< " total iteration: "<< c << "\n";

	c = 0;

	cout << "With memorization,  " << n <<"th value " << fiboNthWithMemo(n);
	cout << " total iteration: " << c << "\n";

	c = 0;

	cout << "Without memorization,  " << n <<"th value " << fiboNthLinearTimeWithoutMemo(n).first;
	cout << " total iteration: " << c << "\n";

    c = 0;

    cout << "With loop,  " << n <<"th value " << fiboWithLoop(n);
    cout << " total iteration: " << c << "\n";

	//fiboShowTillNthWithMemo(n);

	//cin >> n;
	return 0;
}
