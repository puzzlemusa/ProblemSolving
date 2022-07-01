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

using namespace std;

const int maxn = 2e5 + 10;
typedef __int64 Long;
vector<int> colors;
vector<bool> visited;
vector<int> adjacencyList[maxn];
map<int, int> parentNodes;
vector<int>connectedNode;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, m, k;
	for (int i = 1; i <= maxn; i++) {
		adjacencyList[i].clear();
	}

	cin >> n >> m >> k;
	colors.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> colors[i];
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		adjacencyList[a].push_back(b);
		adjacencyList[b].push_back(a);
	}

	int total = 0;
	for (int i = 1; i <= n; i++) {
		stack<int> needToVisit;
		if (!visited[i]) {
			needToVisit.push(i);
			unordered_map<int, int> mp;
			while (!needToVisit.empty()) {
				int u = needToVisit.top();
				needToVisit.pop();
				if (!visited[u]) {
					visited[u] = true;
					mp[colors[u]]++;
					for (int j = 0; j < adjacencyList[u].size(); j++) {
						if (!visited[adjacencyList[u][j]])
							needToVisit.push(adjacencyList[u][j]);
					}
				}
			}
			int maxColor = 0;
			for (std::unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
				maxColor = max(maxColor, it->second);
			}
			total += maxColor;
			mp.clear();
		}
	}

	cout << n - total;

	//cin >> n;
	return 0;
}