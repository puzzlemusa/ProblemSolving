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

class Trie {
public:
    string body;
    bool isLeaf = false;
    map<string, Trie*> childern;

    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int i;
        Trie* curr = this;

        frn(i, sz(word)) {
            string sub = word.substr(0, i + 1);
            if (curr->childern.size() == 0 || curr->childern.find(sub) == curr->childern.end()) {
                curr->childern[sub] = new Trie();
            }
            curr = curr->childern[sub];
        }

        curr->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i;
        Trie* curr = this;
        frn(i, sz(word)) {
            string sub = word.substr(0, i + 1);
            if (curr->childern.find(sub) != curr->childern.end()) {
                curr = curr->childern[sub];
            }
            else {
                return false;
            }
        }
        if (curr->isLeaf)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        int i;
        Trie* curr = this;
        frn(i, sz(word)) {
            string sub = word.substr(0, i + 1);
            if (curr->childern.find(sub) != curr->childern.end()) {
                curr = curr->childern[sub];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif
    Trie sol;
    //vector<int> v = { 5, -3, 5 };
    //vector<int> v = { 1, -2, 3, -2 };
    //vector<int> v = { 3,-1,2,-1 };
    //vector<int> v = { 3, -2, 2, -3 };
    //vector<int> v = { -2, -3, -1 };
    //vector<int> v = { -2 };
    //vector<int> v = { 9,-4,-7,9 };
    vector<int> v = { 7, -10, 7, -10, 7 };

    //cout << sol.maxSubarraySumCircular(v);
    //cin >> n;
    return 0;
}