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
typedef long long Long;
vector<int> holder;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif

	holder.resize(27);

	string h,n;
	h = "asdf";
	n = "df";

	for (int i = 0; i < n.length(); i++) {
		holder[n.at(i) % 96]++;
	}

	for (int i = 0; i < h.length(); i++) {
		holder[h.at(i) % 96]--;
		if (i >= n.length() - 1) {
			int j = 1;
			for (; j <= 26; j++) {
				if (holder[j] != 0)
					break;
			}
			if (j == 27) {
				cout << "Found";
				break;
			}
			holder[h.at(i - (n.length() - 1)) % 96]++;
		}
	}

	//cin >> n;
	return 0;
}