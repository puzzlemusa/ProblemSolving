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
map<string, int> mp;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n;

	cin >> n;

	int tot = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "Tetrahedron")
			tot += 4;
		else if (s == "Cube")
			tot += 6;
		else if (s == "Octahedron")
			tot += 8;
		else if (s == "Dodecahedron")
			tot += 12;
		else if (s == "Icosahedron")
			tot += 20;
	}
	cout << tot;
	//cin >> n;
	//printf("\n");
	return 0;
}