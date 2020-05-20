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
     void inOrder(TreeNode* root) {
         if (root->left != nullptr)
             inOrder(root->left);
         v.push_back(root->val);
         if (root->right != nullptr)
             inOrder(root->right);
     }

     int kthSmallest(TreeNode* root, int k) {
         inOrder(root);
         sort(v.begin(), v.end());
         return v[k-1];
     }
 };
int main() {
    Solution sol;

    TreeNode* root = &TreeNode(5);
    root->left = &TreeNode(3);
    root->right = &TreeNode(6);
    root->left->left = &TreeNode(2);
    root->left->right = &TreeNode(4);
    root->left->left->left = &TreeNode(1);

    cout << (sol.kthSmallest(root, 3)) << endl;
}