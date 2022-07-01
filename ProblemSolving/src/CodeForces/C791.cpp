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
vector<string> cc;
vector<string> output;

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	int n, k;
	cin >> n >> k;
	cc.resize(n-k+1);
	output.resize(n);

	for (int i = 0; i < n -k + 1; i++) {
		cin >> cc[i];
		
	}

	for (int i = 0; i < n; i++) {
		if(i<26)
			output[i] = i+65;
		else {
			char a = 97 + (i % 26);
			string A = "A";
			output[i] = A + a;
		}
	}

	for (int i = 0; i < n - k + 1; i++) {
		if (cc[i] == "NO") {
			if (i + k - 1 >= n)
				output[i] = output[i - (k - 1)];
			else
				output[i+k-1] = output[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i < n - 1)
			cout << output[i] << " ";
		else
			cout << output[i];
	}

	//cin >> n;
	return 0;
}