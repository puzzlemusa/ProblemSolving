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

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        convert(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void convert(vector<vector<int>>& image, int sr, int sc, int newColor, int sourceColor) {
        image[sr][sc] = newColor;

        if (sc < image[sr].size() - 1 && image[sr][sc + 1] == sourceColor && image[sr][sc + 1]!= newColor) {
            convert(image, sr, sc + 1, newColor, sourceColor);
        }

        if (sc > 0 && image[sr][sc - 1] == sourceColor && image[sr][sc - 1] != newColor) {
            convert(image, sr, sc - 1, newColor, sourceColor);
        }

        if (sr < image.size() - 1 && image[sr + 1][sc] == sourceColor && image[sr + 1][sc] != newColor) {
            convert(image, sr + 1, sc, newColor, sourceColor);
        }

        if (sr > 0 && image[sr - 1][sc] == sourceColor && image[sr - 1][sc] != newColor) {
            convert(image, sr - 1, sc, newColor, sourceColor);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;

    //vector<vector<int>> v = { {1,1,1}, {1,1,0}, {1,0,1} };
    vector<vector<int>> v = { {0,0,0}, {0,1,1} };

    vector<vector<int>> r = sol.floodFill(v, 1,1,1);

    int i, j;
    frn(i, sz(r)) {
        frn(j, sz(r[i])) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    //cout << sol.floodFill(v, 1, 1, 2);
    //cin >> n;
    return 0;
}