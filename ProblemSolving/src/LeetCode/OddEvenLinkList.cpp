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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (head == NULL || head == nullptr)
            return head;

        ListNode* curr = head;
        ListNode* oddhead = nullptr;
        ListNode* oddcurr = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* evencurr = nullptr;
        ListNode* newNode = nullptr;
        int i = 1;

        while (true) {
            newNode = new ListNode(curr->val);

            if (i % 2 == 1) {
                if (oddhead == nullptr) {
                    oddcurr = newNode;
                    oddhead = oddcurr;
                    
                }
                else {
                    oddcurr->next = newNode;
                    oddcurr = oddcurr->next;
                }
                    
            }
            else {
                if (evenHead == nullptr) {
                    evencurr = newNode;
                    evenHead = evencurr;
                    
                }
                else {
                    evencurr->next = newNode;
                    evencurr = evencurr->next;
                }
                    
            }
            if (curr->next == nullptr)
                break;
            curr = curr->next;
            i++;
        }

        if (oddhead != nullptr && evenHead != nullptr)
            oddcurr->next = evenHead;

        return oddhead;
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
    ListNode five = ListNode(5);
    ListNode four = ListNode(4, &five);
    ListNode three = ListNode(3, &four);
    ListNode two = ListNode(2, &three);
    ListNode head = ListNode(1, &two);

    ListNode* curr = &head;
    while (true) {
        cout << curr->val << " ";
        if (curr->next == nullptr)
            break;
        curr = curr->next;
    }

    cout << sol.oddEvenList(&head);
    //cin >> n;
    return 0;
}