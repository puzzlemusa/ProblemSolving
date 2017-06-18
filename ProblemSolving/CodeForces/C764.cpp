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
vector<int> adjacencyList[maxn];
vector<int> vertexColor;
vector<int> vr;
map<pair<pair<int, int>, int>, bool> memory;

bool DFS(int parent, int root, int color) {
	pair<pair<int, int>, int> pr = make_pair(make_pair(parent, root), color);
	if (memory.find(pr) != memory.end())
		return memory[pr];

	if (color != vertexColor[root])
		return false;

	for (int i = 0; i < adjacencyList[root].size(); i++) {
		int v = adjacencyList[root][i];
		if (v != parent) {
			bool result = DFS(root, v, color);
			if (!result) {
				return memory[pr] = false;
			}
		}
	}
	return memory[pr] = true;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n;
	for (int i = 1; i <= maxn; i++) {
		adjacencyList[i].clear();
	}
	memory.clear();
	
	cin >> n;
	vertexColor.resize(n+1);

	
	for (int i = 0; i<n - 1; i++) {
		int e1, e2;
		cin >> e1 >> e2;
		adjacencyList[e1].push_back(e2);
		adjacencyList[e2].push_back(e1);
	}

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		vertexColor[i] = a;
		vr.push_back(i);
	}

	bool annoyed = false;
	while (!vr.empty()) {
		int i = vr.back();
		vr.pop_back();
		annoyed = false;
		for (int j = 0; j < adjacencyList[i].size(); j++) {
			int a = adjacencyList[i][j];
			int color = vertexColor[a];
			bool result = DFS(i, a, color);
			if (!result) {
				annoyed = true;
				break;
			}
			else {
				vr.erase(std::remove(vr.begin(), vr.end(), a), vr.end());
			}
		}
		if (!annoyed) {
			cout << "YES\n" << i;
			break;
		}
	}
	if (annoyed) {
		cout << "NO";
	}
	
	//cin >> n;
	//printf("\n");
	return 0;
}