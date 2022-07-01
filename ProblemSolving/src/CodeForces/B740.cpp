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
vector<int> moods;
vector<int> selectedMoodsFreq;
vector<pair<int, int>> subArrays;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, m;
	cin >> n >> m;
	moods.resize(n + 1);
	selectedMoodsFreq.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> moods[i];
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		
		int tot = 0;
		for (int i = a; i <= b; i++) {
			tot += moods[i];
		}
		if (tot > 0) {
			pair<int, int> pr = make_pair(a, b);
			subArrays.push_back(pr);
		}
	}


	for (int i = 1; i <= n; i++) {
		for (std::vector<pair<int, int>>::iterator it = subArrays.begin(); it != subArrays.end(); ++it) {
			if (i >= it->first && i <= it->second)
				selectedMoodsFreq[i]++;
		}
	}

	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += moods[i] * selectedMoodsFreq[i];
	}
	cout << tot;

	//cin >> n;
	return 0;
}