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
    bool xfound = false;
    bool yfound = false;
    int xpar = -1;
    int ypar = -2;
    int xdep = -1;
    int ydep = -2;

    bool isCousins(TreeNode* root, int x, int y) {
        
        test(root, x, y, 0);

        if (xfound && yfound && xpar != ypar && xdep == ydep)
            return true;
        else
            return false;

    }

    void test(TreeNode* root, int x, int y, int depth) {
        if (root->left != nullptr && x == root->left->val) {
            xfound = true;
            xpar = root->val;
            xdep = depth;
        }

        if (root->right != nullptr && x == root->right->val) {
            xfound = true;
            xpar = root->val;
            xdep = depth; 
        }

        if (root->left != nullptr && y == root->left->val) {
            yfound = true;
            ypar = root->val;
            ydep = depth;
        }

        if (root->right != nullptr && y == root->right->val) {
            yfound = true;
            ypar = root->val;
            ydep = depth;
        }

        if (xfound && yfound)
            return;

        if (root->left != nullptr && root->left->val != 0)
            test(root->left, x, y, depth + 1);

        if (root->right != nullptr && root->right->val != 0)
            test(root->right, x, y, depth + 1);
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

    
    TreeNode root = TreeNode(1);
    root.left = &TreeNode(2);
    root.right = &TreeNode(3);

    root.left->left = &TreeNode(NULL);
    root.left->right = &TreeNode(4);

    root.right->left = &TreeNode(NULL);
    root.right->right = &TreeNode(5);

    cout << sol.isCousins(&root, 5, 4);
    //cin >> n;
    return 0;
}