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

using namespace std;

const int maxn = 2e5 + 10;
typedef __int64 Long;
vector<int> coins;
map<int, pair<int, int>> memory;
vector<int>bestWay;

int coinChange(int a) {
	if (a == 0) return 0;
	if (a < 0) return maxn;
	if (memory.find(a) != memory.end())
		return memory[a].first;

	int mn = maxn;
	int mnValue;
	for (int i = 0; i < coins.size(); i++) {
		int coin = coins[i];
		int result = coinChange(a - coin) + 1;
		if (result < mn) {
			mn = result;
			mnValue = coin;
		}
	}
	memory[a] = make_pair(mn, mnValue);

	return mn;
}


int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif

	int n, a;
	cin >> n;
	coins.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	cin >> a;

	bestWay.resize(coinChange(a));

	for (int i = bestWay.size() - 1; i >= 0; i--) {
		bestWay[i] = memory[a].second;
		a -= memory[a].second;
	}

	cout << bestWay.size() << "\n";
	for (int i = 0; i < bestWay.size(); i++) {
		cout << bestWay[i] << " ";
	}

	//cin >> n;
	return 0;
}