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
typedef long long Long;
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

	int a;
	coins = {1,3,5};
	a=20;

	cout << coinChangeWithLoop(coins, a) << "\n";
	cout << coinChange(a) << "\n";

	//ShowChanges(a);

	//cin >> n;
	return 0;
}