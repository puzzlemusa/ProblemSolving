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

class StockSpanner {
public:
    stack <int> st;
    vector <int> v;
    int res, i;
    StockSpanner() {
        i = 0;
    }
    int next(int price) {
        i++;
        while (!st.empty() && price >= v[st.top() - 1])
            st.pop();
        res = st.empty() ? i : i - (st.top());
        v.push_back(price);
        st.push(i);
        return res;
    }
};
int main() {
    StockSpanner ob;
    cout << (ob.next(100)) << endl;
    cout << (ob.next(80)) << endl;
    cout << (ob.next(60)) << endl;
    cout << (ob.next(70)) << endl;
    cout << (ob.next(60)) << endl;
    cout << (ob.next(75)) << endl;
    cout << (ob.next(85)) << endl;

    /*cout << (ob.next(10)) << endl;
    cout << (ob.next(4)) << endl;
    cout << (ob.next(5)) << endl;
    cout << (ob.next(90)) << endl;
    cout << (ob.next(120)) << endl;
    cout << (ob.next(80)) << endl;*/
}