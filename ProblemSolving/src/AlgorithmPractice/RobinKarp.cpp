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
int prime = 31;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	string text, pattern;
    text = "dfasdfrdf";
    pattern = "df";
    vector<Long> textHash;
	textHash.resize(text.size());

	Long patternHash = 0;
	for (int i = 0; i < pattern.size(); i++) {
		patternHash += pattern.at(i) * pow(prime, i);
	}

	Long tot = 0;
	for (int i = 0; i < text.size(); i++) {
		tot += text.at(i) * pow(prime, i);
		textHash[i] = tot;

		if(i==pattern.size()-1 && textHash[i] == patternHash)
			cout << "Pattern found at position " << 0 << "\n";

		if (i > pattern.size() - 1) {
			if ((textHash[i] - textHash[i - pattern.size()]) / pow(prime, i - (pattern.size()-1)) == patternHash)
				cout << "Pattern found at position " << i - (pattern.size() - 1) << "\n";
		}
	}

	//cin >> n;
	return 0;
}