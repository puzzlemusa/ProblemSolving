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

const int maxn = 2e5 + 10;
typedef __int64 Long;
vector<Long> arr;
map<Long, Long>mp;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n;
	cin >> n;
	arr.resize(n);

	for (Long i = 0; i < n; i++) {
		Long a;
		cin >> a;
		mp[a]++;
	}

	auto itE = mp.end();
	auto itS = mp.begin();
	auto middle = --itE;
	--middle;

	if (mp.size() <= 2 || n==2) {
		cout << "YES";
		return 0;
	}
	else if (mp.size() > 3) {
		cout << "NO";
		return 0;
	}
	else if (itE->first - middle->first != middle->first - itS->first) {
		cout << "NO";
		return 0;
	}

	cout << "YES";

	//cin >> n;
	return 0;
}