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
#include <functional>
#include <iomanip>

using namespace std;

const int maxn = 2e5 + 10;
typedef __int64 Long;
vector<Long> arr;

Long binarySearch(Long value, Long left, Long right) {
	int middle = (left + right) / 2;
	while (left <= right) {
		middle = (left + right) / 2;
		if (arr[middle] > value) {
				right = middle - 1;
		}
		else if(arr[middle] <= value) {
				left = middle + 1;
		}
		else {
			return middle + 1;
		}
	}
	return left;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input1.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n, q;
	cin >> n;
	arr.resize(n);

	for (Long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	std::sort(arr.begin(), arr.end());

	cin >> q;

	for (Long i = 0; i < q; i++) {
		Long a;
		cin >> a;
		//cout << binarySearch(a, 0, n-1) << "\n";
		cout << upper_bound(arr.begin(), arr.end(), a) - arr.begin() << "\n";
	}

	//cin >> n;
	return 0;
}