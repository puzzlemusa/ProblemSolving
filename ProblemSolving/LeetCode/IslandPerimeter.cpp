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
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0, i,j;

        frn(i, sz(grid)){
            frn(j, sz(grid[i])){
                int t = 4;
                if(grid[i][j] == 1){
                    if(i!=0 && grid[i-1][j] == 1)
                        t--;
                    if(j!=0 && grid[i][j-1] == 1)
                        t--;
                    if(i != sz(grid)-1 && grid[i+1][j] == 1)
                        t--;
                    if(j != sz(grid[i])-1 &&grid[i][j+1] == 1)
                        t--;

                    res += t;
                }
            }
        }
        return  res;
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
	int n, i, j;
    vector<vector<int>> in = {{0,1,0,0},
                              {1,1,1,0},
                              {0,1,0,0},
                              {1,1,0,0}};

	cout << sol.islandPerimeter(in);


	//cin >> n;
	return 0;
}