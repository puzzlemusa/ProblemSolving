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
int k = 0;

void add(string& s, int i) {
	if (holder[s.at(i) % 96] == 0)
		k++;
	else if (holder[s.at(i) % 96] == -1)
		k--;
	holder[s.at(i) % 96]++;
}

void remove(string& s, int i) {
	if (holder[s.at(i) % 96] == 1)
		k--;
	else if (holder[s.at(i) % 96] == 0)
		k++;
	holder[s.at(i) % 96]--;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif

	holder.resize(27);

	string h, n;
    h = "asds";
    n = "sds";

	for (int i = 0; i < n.length(); i++) {
		add(n, i);
	}

	
	for (int i = 0; i < h.length(); i++) {
		remove(h, i);
		if (i >= n.length() - 1) {
			
			if (k == 0) {
				cout << "Found";
				break;
			}
			add(h, i - (n.length() - 1));
		}
	}

	//cin >> n;
	return 0;
}