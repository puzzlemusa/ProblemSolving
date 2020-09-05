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

const int maxn = 2147483647;
vector<int>v;

class Solution {
public:
    pair<int, int>p = make_pair(0,0);
    string largestTimeFromDigits(vector<int>& A) {
        if(A[0] == 0 && A[1] == 0 && A[2] == 0 && A[3] == 0)
            return "00:00";
        combination(A, 0);
        if(p.first==0 && p.second==0)
            return "";
        else{
            string hs, ms;
            if(p.first<10)
                hs = "0" + to_string(p.first);
            else
                hs = to_string(p.first);
            if(p.second<10)
                ms = "0" + to_string(p.second);
            else
                ms = to_string(p.second);
            string res = hs + ":" + ms;
            return res;
        }
    }

    void swp(int &i, int &j){
        int temp = i;
        i = j;
        j = temp;
    }

    void combination(vector<int> A, int start){
        int i;
        if(start == sz(A)){
            //cout << A[0] <<" " << A[1] <<" " << A[2]<<" " << A[3]<< "\n";
            int h = (A[0]*10)+A[1];
            int m = (A[2]*10)+A[3];
            if(h<24 && m<60){
                if(h>p.first)
                    p = make_pair(h, m);
                else if(h==p.first && m>p.second)
                    p = make_pair(h, m);
            }
        }
        else{
            frv(i, start, sz(A)){
               if(i != start)
                    swp(A[i], A[start]);
               combination(A, start+1);
            }
        }
    }
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w", stdout);
#endif
	Solution sol;
	vector<int>v = {1,0,0,1};
	cout << sol.largestTimeFromDigits(v);


	//cin >> n;
	return 0;
}