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

int coinChangeWithLoop(vector<int>v, int money){
    int i, j;
    vector<int>minVal(money+1, 0);

    frv(i,1,money+1){
        int mn = INT_MAX;
        frn(j, sz(v)){
            int c = INT_MAX;
            if(v[j]<=i)
                c = minVal[i-v[j]] + 1;
            mn = min(mn, c);
        }
        minVal[i] = mn;
    }

    return minVal[money];
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif

	int n, a;
	coins = {1,3,5};
	a = 20;

	cout << coinChangeWithLoop(coins, a)<< endl;
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