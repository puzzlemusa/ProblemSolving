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
const int maxn = 1000000007;

long countSubs(string s) {
	long a=0, b=0, c=0, d=0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'a')
			a++;
		else if (s.at(i) == 'b')
			b++;
		else if (s.at(i) == 'c')
			c++;
		else if (s.at(i) == 'd')
			d++;
	}

	int x = min(a, b)+1, y = min(c, d)+1;

	return (x*y - 1)% maxn;
}

int main() {
	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++) {
		string s;
		cin >> s;
		long result = countSubs(s);
		cout << result << endl;
	}
	return 0;
}
