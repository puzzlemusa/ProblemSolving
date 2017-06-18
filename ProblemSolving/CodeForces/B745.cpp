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

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, m;
	cin >> n >> m;

	int totalX = 0;
	for (int i = 0; i < n*m; i++) {
		char a;
		cin >> a;
		if (a == 'X')
			totalX++;
	}

	if (totalX * 2 > n*m && (totalX % n != 0 && totalX % m != 0)) {
		cout << "NO";
	}
	else {
		if (totalX % n == 0) {
			cout << "YES";
			return 0;
		}
		else {
			if (totalX/n==0 && totalX % n <= n / 2) {
				cout << "YES";
				return 0;
			}
			if (totalX / n >= 1 && totalX % n == n / 2) {
				cout << "YES";
				return 0;
			}
		}
		if (totalX % m == 0) {
			cout << "YES";
			return 0;
		}
		else {
			if (totalX / m == 0 && totalX % m <= m / 2) {
				cout << "YES";
				return 0;
			}
			if (totalX / m >= 1 && totalX % m == m / 2) {
				cout << "YES";
				return 0;
			}
		}
		cout << "NO";
	}

	//printf("\n");
	return 0;
}