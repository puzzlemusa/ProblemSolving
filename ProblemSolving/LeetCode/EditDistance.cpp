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
#include <unordered_map>
#include <functional>
#include <iomanip>

using namespace std;

#define frn(i,n) for(i=0;i<n;i++)
#define frN(i,n) for(i=1;i<=n;i++)
#define frr(i,n) for(i=n-1;i>=0;i--)
#define frv(i,a,n) for(i=a;i<n;i++)
#define frl(i,v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v,a) memset(v,a,sizeof(v))
#define pi (2*acos(0))
#include <bitset>
const int maxn = 2147483647;
vector<int>v;
map<pair<int, int>, int> mem;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return calc(word1, word2, 0, 0);
    }

    int calc(string word1, string word2, int i, int j) {
        if (mem.find(make_pair(i, j)) != mem.end())
            return mem[make_pair(i, j)];

        else if (i == sz(word1)) 
            return mem[make_pair(i, j)] = sz(word2) - j;
                  
        else if (j == sz(word2))
            return mem[make_pair(i, j)] = sz(word1) - i;

        else if (word1[i] == word2[j])
            return mem[make_pair(i, j)] = calc(word1, word2, i + 1, j + 1);

        else {
            int ins = 1 + calc(word1, word2, i, j + 1);
            int del = 1 + calc(word1, word2, i + 1, j);
            int rep = 1 + calc(word1, word2, i + 1, j + 1);

            return mem[make_pair(i, j)] = min(min(ins, del), rep);
        }
    }
};
int main() {
    Solution sol;
    cout << sol.minDistance("intention", "execution");
    return 0;
}