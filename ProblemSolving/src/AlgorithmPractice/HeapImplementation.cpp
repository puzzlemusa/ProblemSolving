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

const int maxn = 1e9 + 10;
typedef long long Long;
vector<int>v;
unordered_map<int, int>mp;

int maxSize = 10;
class MinHeap{
    vector<int> arr;
    int size = 0;
public:
    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return (i*2)+1;
    }

    int right(int i){
        return (i*2)+2;
    }

    void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void insert(int val){
        if(size == maxSize){
            cout << "Overflow";
            return;
        }
        size++;
        int curr_loc = size - 1;
        arr.push_back(val);

        while(curr_loc != 0 && arr[curr_loc] < arr[parent(curr_loc)]){
            swap(&arr[curr_loc], &arr[parent(curr_loc)]);
            curr_loc = parent(curr_loc);
        }
    }

    int extractMin(){
        if(size == 0)
            cout<< "Underflow";

        int root = arr[0];
        arr[0] = arr[size -1];
        size--;
        minHeapify(0);
        return root;
    }

    void minHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < size && arr[l] < arr[i])
            smallest = l;
        if(l < size && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != i){
            swap(&arr[i], &arr[smallest]);
            minHeapify(smallest);
        }
    }

    void deleteKey(int i){
        if(i == size || size == 0)
            cout << "Invalid key.";

        arr[i] = INT_MIN;

        while(i != 0 && arr[i] < arr[parent(i)]){
            swap(&arr[i], &arr[parent(i)]);
            i = parent(i);
        }
        extractMin();
    }
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
    MinHeap minHeap;

    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(21);
    minHeap.insert(15);
    minHeap.insert(1);
    minHeap.insert(4);
    minHeap.deleteKey(1);
    cout << minHeap.extractMin() << endl;
    cout << minHeap.extractMin() << endl;
    cout << minHeap.extractMin() << endl;

	return 0;
}
