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
    typedef long long Long;

    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *res = head;
        int index = 1;
        map<int, ListNode *> mm;
        while (head != nullptr) {
            mm[index++] = head;
            head = head->next;
        }
        ListNode *parentOfTarget = mm[index - (n + 1)];
        ListNode *target = mm[index - n];

        if (parentOfTarget == nullptr) {
            if (target->next == nullptr)
                return nullptr;
            else
                return target->next;
        }


        if (target->next != nullptr)
            parentOfTarget->next = target->next;
        else
            parentOfTarget->next = nullptr;

        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif
    typedef long long Long;
    Solution sol;
    ListNode five = ListNode(5);
    ListNode four = ListNode(4);
    four.next = &five;
    ListNode three = ListNode(3);
    three.next = &four;
    ListNode two = ListNode(2);
    //two.next = &three;
    ListNode one = ListNode(1);
    one.next = &two;
    cout << sol.removeNthFromEnd(&one, 1)->val << endl;

    //cin >> n;
    return 0;
}