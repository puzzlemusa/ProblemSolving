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

#define frn(i, n) for(i=0;i<n;i++)
#define frN(i, n) for(i=1;i<=n;i++)
#define frr(i, n) for(i=n-1;i>=0;i--)
#define frv(i, a, n) for(i=a;i<n;i++)
#define frl(i, v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v, a) memset(v,a,sizeof(v))
#define pi (2*acos(0))

#include <bitset>

const int maxn = 2147483647;
vector<int> v;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode head;
        ListNode *res = &head;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                res->next = list1;
                list1 = list1->next;
            } else {
                res->next = list2;
                list2 = list2->next;
            }
            res = res->next;
        }
        res->next = list1 ? list1 : list2;
        return head.next;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;

    ListNode one = ListNode(1);
    ListNode one1 = ListNode(1);
    ListNode two = ListNode(2);
    ListNode three = ListNode(3);
    ListNode four = ListNode(4);
    ListNode four1 = ListNode(4);

    one.next = &two;
    two.next = &four;

    one1.next = &three;
    three.next = &four1;

    ListNode *result;
    result = sol.mergeTwoLists(&one, &one1);
    //result = sol.mergeTwoLists(nullptr, nullptr);
    //res = sol.mergeTwoLists(nullptr, &one1);
    //res = sol.mergeTwoLists(&one, nullptr);
    return 0;
}