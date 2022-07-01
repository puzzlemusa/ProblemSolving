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
vector<int> letters;
int k = 26;
int que = 0;
map<int, bool> quePos;
vector<int> missingLetters;

void add(string& s, int i) {
	if (s.at(i) == '?') {
		que--;
		quePos[i] = false;
		s.at(i) = 'A';
	}
	else {
		if (letters[s.at(i) % 65] == 0)
			k++;
		else if (letters[s.at(i) % 65] == -1)
			k--;
		letters[s.at(i) % 65]++;
	}
}

void remove(string& s, int i) {
	if (s.at(i) == '?') {
		que++;
		quePos[i] = true;
	}
	else {
		if (letters[s.at(i) % 65] == 1)
			k--;
		else if (letters[s.at(i) % 65] == 0)
			k++;
		letters[s.at(i) % 65]--;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	string s;
	letters.resize(26);
	std::fill(letters.begin(), letters.end(), 1);

	cin >> s;
	
	if (s.length() < 26) {
		cout << -1;
		return 0;
	}

	bool found = false;
	int i;
	for (i = 0; i < s.length(); i++) {
		remove(s, i);
		if (i >= letters.size() - 1) {

			if (k == que) {
				found = true;
				break;
			}
			add(s, i - (letters.size() - 1));
		}
	}
	
	if (found) {
		for (int j = 0; j < letters.size(); j++) {
			if (letters[j] != 0) {
				missingLetters.push_back(j);
			}
		}

		std::vector<int>::iterator it = missingLetters.begin();
		for (int j = 0; j < s.size(); j++) {

			if (s.at(j) == '?') {
				if (quePos[j])
					s.at(j) = *it++ + 65;
				else
					s.at(j) = 'A';
			}
		}
		cout << s;
	}
	else
		cout << -1;

	//cin >> n;
	return 0;
}