#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int maxn = 1e5 + 10;
vector<long> adjacencyList[maxn];
vector<bool> visited;

int main() {
	long q;
	cin >> q;
	for (long a0 = 0; a0 < q; a0++) {

		long n;
		long m;
		long x;
		long y;
		
		cin >> n >> m >> x >> y;

		for (long i = 1; i <= n; i++) {
			adjacencyList[i].clear();
		}
		
		visited.clear();
		visited.resize(n + 1);
		
		for (long a1 = 0; a1 < m; a1++) {
			long a;
			long b;
			cin >> a >> b;

			adjacencyList[a].push_back(b);
			adjacencyList[b].push_back(a);
		}

		if (y >= x) {
			cout << n*x << "\n";
			continue;
		}

		long totalCost = 0;
		for (long i = 1; i <= n; i++) {
			stack<long> needToVisit;
			long totalNodehere = 0;
			if (!visited[i]) {
				needToVisit.push(i);
				while (!needToVisit.empty()) {
					int u = needToVisit.top();
					needToVisit.pop();
					if (!visited[u]) {
						visited[u] = true;
						totalNodehere++;
						for (int j = 0; j < adjacencyList[u].size(); j++) {
							if (!visited[adjacencyList[u][j]]) {
								needToVisit.push(adjacencyList[u][j]);
							}
						}
					}
				}
				totalCost += x + y*(totalNodehere - 1);
			}
		}
		cout << totalCost << "\n";
	}
	return 0;
}