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

typedef long long Long;

const int maxn = 1e9 + 10;
vector<vector<char>>v;

class Solution {
public:
    string reverseWords(string s) {
        int i;
        bool spaceFound = false;
        bool wordStarted = false;
        vector<string>words;
        string word = "";
        frn(i, sz(s)){
            if(s[i]==' '){
                if(!spaceFound){
                    wordStarted = false;
                    spaceFound = true;
                    if(word != ""){
                        words.push_back(word);
                        word = "";
                    }
                }
            }else{
                spaceFound = false;
                if(wordStarted){
                    word += s[i];
                }else{
                    wordStarted = true;
                    word = s[i];
                }
            }
        }

        if(word != "")
            words.push_back(word);

        string res;
        frr(i, sz(words)){
            res.append(words[i]);
            if(i!=0)
                res += " ";
        }

        return res;
    }
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	Solution sol;

	cout << sol.reverseWords("  hello world!  ");

	//cin >> n;
	return 0;
}