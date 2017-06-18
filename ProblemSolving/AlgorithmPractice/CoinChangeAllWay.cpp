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
map<int, int> memory;
vector<int> v;

int coinChange(int a) {
	if (a == 0) 
		return 1;
	if (a < 0) return 0;
	if (memory.find(a) != memory.end())
		return memory[a];

	int result = 0;
	for (int i = 0; i < coins.size(); i++) {
		int coin = coins[i];
		result += coinChange(a - coin);
	}
	memory[a] = result;

	return result;
}

int ShowChanges(int a) {
	if (a == 0) {
		cout << "\n";
		for (auto it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
		return 1;
	}
	if (a < 0) return 0;
	int result = 0;
	for (int i = 0; i < coins.size(); i++) {
		int coin = coins[i];
		v.push_back(coin);
		result += ShowChanges(a - coin);
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

	int n, a;
	cin >> n;
	coins.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	cin >> a;

	cout << coinChange(a) << "\n";

	ShowChanges(a);

	//cin >> n;
	return 0;
}