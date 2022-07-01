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

#define frn(i,n) for(i=0;i<n;i++)
#define frN(i,n) for(i=1;i<=n;i++)
#define frr(i,n) for(i=n-1;i>=0;i--)
#define frv(i,a,n) for(i=a;i<n;i++)
#define frl(i,v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()

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

int coinChangeWithLoop(vector<int>v, int money){
    int i, j;
    vector<int>totVal(money+1, 0);
    totVal[0]=1;
    frv(i,1,money+1){
        int c = 0;
        frn(j, sz(v)){
            if(v[j]<=i)
                c += totVal[i-v[j]];
        }
        totVal[i] = c;
    }

    return totVal[money];
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif

	long a;
	coins = {1,3,5};
	a = 20;

	cout << coinChangeLessComplexity(a, 0) << "\n";
	ShowChanges(a, 0);

	//cin >> n;
	return 0;
}