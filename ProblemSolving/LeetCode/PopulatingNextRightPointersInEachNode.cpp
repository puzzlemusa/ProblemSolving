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

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;
        queue<Node *> q;
        q.push(root);
        int lvl = 0;
        Node *node;
        Node *prvNode = nullptr;
        while (!q.empty()) {
            int counter = q.size();
            while (counter-- != 0) {
                node = q.front();
                q.pop();
                //cout << node->val << " level: " << lvl << " counter: " << counter << endl;
                if (node->left != nullptr) {
                    q.push(node->left);
                    q.push(node->right);
                }
                if (prvNode != nullptr)
                    prvNode->next = node;

                prvNode = node;
            }
            lvl++;
            prvNode = nullptr;
        }
        return root;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;

    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(4);
    Node five = Node(5);
    Node six = Node(6);
    Node seven = Node(7);

    three.left = &six;
    three.right = &seven;
    two.left = &four;
    two.right = &five;
    one.left = &two;
    one.right = &three;

    Node *res = sol.connect(&one);

    return 0;
}