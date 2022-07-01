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


int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		int k;
		cin >> n >> k;
		if (((k - 1) | k) > n && k % 2 == 0) {
			cout << (k - 2) << "\n";
		}
		else {
			cout << (k - 1) << "\n";
		}
	}
	return 0;
}
