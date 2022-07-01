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
vector<int> adjacencyList[maxn];
set<int> nodeToVisit;
map<pair<int, int>, int> relations;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int m, n;
	for (int i = 1; i <= maxn; i++) {
		adjacencyList[i].clear();
	}


	int mx = 0, v = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjacencyList[a].push_back(b);
		adjacencyList[b].push_back(a);

		relations[make_pair(a, b)] = a;

		if (adjacencyList[a].size() > mx) {
			mx = adjacencyList[a].size();
			v = a;
		}
		if (adjacencyList[b].size() > mx) {
			mx = adjacencyList[b].size();
			v = b;
		}
	}

	//for (std::set<int>::iterator it = nodeToVisit.begin(); it != nodeToVisit.end(); ++it) {
		int i = v;
		for (int j = 0; j < adjacencyList[i].size(); j++) {
			for (int k = j + 1; k < adjacencyList[i].size(); k++) {
				int a = adjacencyList[i][j];
				int b = adjacencyList[i][k];
				if (relations.find(make_pair(a, b)) == relations.end() && relations.find(make_pair(b, a)) == relations.end()) {
					cout << "NO";
					return 0;

				}
			}
		}
	//}

	cout << "YES";

	//cin >> n;
	return 0;
}