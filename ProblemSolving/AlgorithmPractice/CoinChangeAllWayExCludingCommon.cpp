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
vector<long> coins;
vector<int> v;
map<pair<long, long>, long> memory;

long coinChange(long a, long i) {
	if (a == 0) return 1;
	if (a < 0) return 0;
	if (memory.find(make_pair(a,i)) != memory.end())
		return memory[make_pair(a, i)];

	long result = 0;
	for (; i < coins.size(); ++i) {
		long coin = coins[i];
		result += coinChange(a - coin, i);
	}
	memory[make_pair(a, i)] = result;

	return result;
}


long coinChangeLessComplexity(long a, long i) {
	if (a == 0) return 1;
	if (a < 0 || i==coins.size()) return 0;
	if (memory.find(make_pair(a, i)) != memory.end())
		return memory[make_pair(a, i)];

	long result = coinChangeLessComplexity(a - coins[i], i) + coinChangeLessComplexity(a, i+1);
	memory[make_pair(a, i)] = result;

	return result;
}

int ShowChanges(int a, int i) {
	if (a == 0) {
		cout << "\n";
		for (auto it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
		return 1;
	}
	if (a < 0) return 0;
	int result = 0;
	for (; i < coins.size(); i++) {
		int coin = coins[i];
		v.push_back(coin);
		result += ShowChanges(a - coin, i);
		v.erase(--v.end());
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif

	long n, a;
	cin >> a >> n;
	coins.resize(n);

	for (long i = 0; i < n; i++) {
		cin >> coins[i];
	}

	cout << coinChangeLessComplexity(a, 0) << "\n";
	ShowChanges(a, 0);

	//cin >> n;
	return 0;
}