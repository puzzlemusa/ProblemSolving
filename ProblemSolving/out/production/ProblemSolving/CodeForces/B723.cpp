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
	int s;
	string n;

	cin >> s;
	cin >> n;

	int maxL = 0, wordIn = 0;
	bool wordStart = true;
	bool inPar = false;
	int wordLen = 0;
	for (int i = 0; i < n.length(); i++) {
		char c = n.at(i);

		if (c == '_' ) {
			if (wordLen == 0) {
				wordStart = true;
			}
			else {
				if (!inPar) {
					maxL = max(maxL, wordLen);
				}
				else {
					wordIn++;
				}
				wordStart = false;
			}
			wordLen = 0;
		}
		else if (c=='(') {
			if (wordLen != 0) {
				maxL = max(maxL, wordLen);
			}
			inPar = true;
			wordStart = true;
			wordLen = 0;
		}
		else if (c == ')') {
			if (wordLen != 0) {
				wordIn++;
			}
			inPar = false;
			wordStart = false;
			wordLen = 0;
		}
		else {
			wordLen++;
			if (i == n.length() - 1) {
				maxL = max(maxL, wordLen);
			}
		}

	}
	
	cout << maxL << " " << wordIn;
	//cin >> n;
	//printf("\n");
	return 0;
}