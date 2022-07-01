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
vector<int> students;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Long n;
	cin >> n;
	students.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> students[i];
	}

	bool carry = false;
	for (int i = 0; i < n; i++) {
		if (students[i] % 2 == 1) {
			if (carry)
				carry = false;
			else
				carry = true;
		}
		if (students[i] == 0 && carry) {
			break;
		}
	}
	if(carry)
		cout << "NO";
	else
		cout << "YES";

	//cin >> n;
	return 0;
}