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
#include <functional>
#include <iomanip>

using namespace std;

const int maxn = 1e5 + 10;

int main() {

	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	freopen("D://output.txt","w",stdout);
#endif

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> minHeap;
	std::priority_queue<int> maxHeap;
	std::cout << std::fixed;
	std::cout << std::setprecision(1);
	for (int i = 1; i <= n; i++) {
		int value;
		cin >> value;

		if (i == 1) {
			maxHeap.push(value);
		}
		else if (value <= maxHeap.top()) {
			if (maxHeap.size() > minHeap.size()) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
				maxHeap.push(value);
			}
			else {
				maxHeap.push(value);
			}
		}
		else {
			if (minHeap.size() > maxHeap.size()) {
				if (value > minHeap.top()) {
					maxHeap.push(minHeap.top());
					minHeap.pop();
					minHeap.push(value);
				}
				else {
					maxHeap.push(value);
				}
			}
			else {
				minHeap.push(value);
			}
		}

		if (i % 2 == 1) {
			if (minHeap.size() > maxHeap.size())
				cout << (float)minHeap.top() << "\n";
			else
				cout << (float)maxHeap.top() << "\n";
		}
		else {
			float result = minHeap.top() + maxHeap.top();
			result /= 2;
			cout << result << "\n";
		}
	}

	return 0;
}