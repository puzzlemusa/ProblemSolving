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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr)
            return root2;

        if (root2 == nullptr)
            return root1;

        root1->val = root1->val + root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
#ifdef localhost
    freopen("E://input.txt", "r", stdin);
    //freopen("E://output.txt","w", stdout);
#endif

    Solution sol;

    TreeNode one = TreeNode(1);
    TreeNode two = TreeNode(2);
    TreeNode three = TreeNode(3);
    TreeNode five = TreeNode(5);
    three.left = &five;
    one.left = &three;
    one.right = &two;

    TreeNode one2 = TreeNode(1);
    TreeNode two2 = TreeNode(2);
    TreeNode three2 = TreeNode(3);
    TreeNode four = TreeNode(4);
    TreeNode six = TreeNode(6);
    TreeNode seven = TreeNode(71);

    one2.right = &four;
    three2.left = &six;
    three2.right = &seven;
    two2.left = &one2;
    two2.right = &three2;

    TreeNode *res = sol.mergeTrees(&one, &two2);

    return 0;
}