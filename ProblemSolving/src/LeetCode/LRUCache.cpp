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

vector<int>v;


class TwoWayNode{
public:
    int key;
    int val;
    TwoWayNode* back;
    TwoWayNode* front;
    TwoWayNode(){}
    TwoWayNode(int k, int v): key(k), val(v), back(NULL), front(NULL) {}
};

class LRUCache {
public:

    map<int, TwoWayNode*> mp;
    int maxLength;
    TwoWayNode *start;
    TwoWayNode *end;

    LRUCache(): start(NULL), end(NULL){}
    LRUCache(int capacity) {
        maxLength = capacity;
        start = new TwoWayNode();
        end = new TwoWayNode();
        start->front = nullptr;
        start->back = nullptr;
        end->back = nullptr;
    }

    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else{
            TwoWayNode *twoWayNode = mp[key];
            removeFromLinkedList(twoWayNode);

            TwoWayNode *newNode = new TwoWayNode(key, twoWayNode->val);;
            addInFront(newNode);

            return twoWayNode->val;
        }
    }

    void removeFromLinkedList(TwoWayNode *twoWayNode){
        twoWayNode->front->back = twoWayNode->back;
        twoWayNode->back->front = twoWayNode->front;
    }

    void addInFront(TwoWayNode *twoWayNode){
        twoWayNode->front = start;
        twoWayNode->back = start->back;

        start->back->front = twoWayNode;
        start->back = twoWayNode;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            TwoWayNode *twoWayNode = mp[key];
            twoWayNode->val = value;
            removeFromLinkedList(twoWayNode);
            addInFront(twoWayNode);
        }else{
            TwoWayNode *newNode = new TwoWayNode(key, value);
            if(sz(mp) == maxLength){
                mp.erase(end->front->key);
                removeFromLinkedList(end->front);
            }

            if(start->back == nullptr){
                start->back = newNode;
                end->front = newNode;
                newNode->front = start;
                newNode->back = end;
            }else
                addInFront(newNode);
            mp[key] = newNode;
        }
    }
};

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("E://input.txt", "r", stdin);
	//freopen("E://output.txt","w",stdout);
#endif
	LRUCache cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;

    //cin >> n;
	return 0;
}