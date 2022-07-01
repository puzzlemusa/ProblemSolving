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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(vector<int> v, int start, int end){
    int pivot = v[end];
    int i = start - 1, j;

    frv(j, start, end){
        if(v[j] <= pivot){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i+1], &v[end]);
    return i+1;
}

vector<int> quickSort(vector<int> v, int start, int end){
    if(start < end){
        int pivot = partition(v, start, end);
        quickSort(v, start, pivot-1);
        quickSort(v, pivot, end);
    }

    return v;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
    int i;
    //vector<int> v = {4, 2, 7, 9, 1, 5};
    vector<int> v = {4, 2, 7};
    quickSort(v, 0, sz(v)-1);

    frn(i, sz(v)){
       cout << v[i] << " ";
    }
	//cin >> n;
	return 0;
}