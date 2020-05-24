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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int i = 0, j = 0;

        if (sz(A) == 0 || sz(B) == 0)
            return res;

        while (i < sz(A) && j < sz(B)) {
            int s, e;
            if (A[i][0] <= B[j][0] && B[j][0] <= A[i][1]) {
                s = B[j][0];
                if (B[j][1] <= A[i][1]) {
                    e = B[j][1];
                    res.push_back({ s,e });
                }
                else if (A[i][1] < B[j][1]) {
                    e = A[i][1];
                    res.push_back({ s,e });
                }
            }
            else if (B[j][0] <= A[i][0] && A[i][0] <= B[j][1]) {
                s = A[i][0];
                if (A[i][1] <= B[j][1]) {
                    e = A[i][1];
                    res.push_back({ s,e });
                }
                else if (B[j][1] < A[i][1]) {
                    e = B[j][1];
                    res.push_back({ s,e });
                }
            }

            if (A[i][1] > B[j][1])
                j++;
            else
                i++;
        }

        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> A = { {0,2} ,{5,10},{13,23},{24,25} };
    vector<vector<int>> B = { {1,5} ,{8,12},{15,24},{25,26} };
    vector<vector<int>> res = sol.intervalIntersection(A, B);
    int i, j;
    frn(i, sz(res))
        cout << res[i][0] << " " << res[i][1] << endl;


    
}