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

typedef __int64 Long;

const int maxn = 1e9 + 10;
vector<int>v;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int c = (l1->val + l2->val) / 10, v;
	ListNode* r = new ListNode((l1->val + l2->val) % 10);
	ListNode* end = r;
	l1 = l1->next;
	l2 = l2->next;
	while (l1 != NULL && l2 != NULL) {
		v = (l1->val + l2->val + c) % 10;
		c = (l1->val + l2->val + c) / 10;

		if(end != NULL)
			while (end->next != NULL)
				end = end->next;

		end->next = new ListNode(v);

		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1 != NULL) {
		v = (l1->val + c) % 10;
		c = (l1->val + c) / 10;

		while (end->next != NULL)
			end = end->next;

		end->next = new ListNode(v);

		l1 = l1->next;
	}

	while (l2 != NULL) {
		v = (l2->val + c) % 10;
		c = (l2->val + c) / 10;

		while (end->next != NULL)
			end = end->next;

		end->next = new ListNode(v);

		l2 = l2->next;
	}

	if (c == 1) {
		while (end->next != NULL)
			end = end->next;

		end->next = new ListNode(1);
	}

	return r;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i, j, m;

	cin >> n >> m;

	string s1;
	s1 = to_string(n);

	ListNode* a = new ListNode(s1.at(sz(s1) - 1) - 48);
	ListNode* end1 = a;
	frr(i, sz(s1) - 1) {
		while (end1->next != NULL)
			end1 = end1->next;

		end1->next = new ListNode(s1.at(i) - 48);
	}

	string s2;
	s2 = to_string(m);

	ListNode* b = new ListNode(s2.at(sz(s2) - 1) - 48);
	ListNode* end2 = b;
	frr(i, sz(s2) - 1) {
		while (end2->next != NULL)
			end2 = end2->next;

		end2->next = new ListNode(s2.at(i) - 48);
	}

	addTwoNumbers(a, b);

	//cin >> n;
	return 0;
}