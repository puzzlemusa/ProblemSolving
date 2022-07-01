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
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()

const int maxn = 1e5 + 10;
typedef long long Long;
vector<int>adj[maxn];

struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* insert(Node* root, int val) {
	if (root == NULL) {
		root = new Node();
		root->val = val;
		root->left = root->right = NULL;
	}

	else if (val <= root->val) {
		root->left = insert(root->left, val);
	}
	
	else if (val > root->val) {
		root->right = insert(root->right, val);
	}

	return root;
}

void DFS(Node* root) {
	if (root != NULL)
		cout << root->val << " ";

	if (root->left != NULL)
		DFS(root->left);

	if (root->right != NULL)
		DFS(root->right);
}

void IDDFS(Node* root, int l, int c) {
	if (root != NULL) {
		if (l == c) {
			cout << root->val << " ";
			return;
		}
	}

	if (root->left != NULL)
		IDDFS(root->left, l, c+1);

	if (root->right != NULL)
		IDDFS(root->right, l, c+1);
}

void BFS(Node* root) {
	queue<Node*>st;
	if (root != NULL) {
		st.push(root);
	}
	while (!st.empty()) {
		cout << st.front()->val << " ";
		Node* curr = st.front();
		st.pop();

		if (curr->left != NULL)
			st.push(curr->left);

		if (curr->right != NULL)
			st.push(curr->right);
	}
}

int GetHeight(Node* root) {
	if (root == NULL)
		return -1;

	int left = GetHeight(root->left);
	int right = GetHeight(root->right);

	if (left > right)
		return left + 1;
	else
		return right + 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	//freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
	int n, i;

	Node* root = NULL;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 7);
	insert(root, 8);
	insert(root, 2);
	insert(root, 4);
	insert(root, 6);
	insert(root, 10);
	insert(root, 12);

	cout << "DFS: ";
	DFS(root);
	cout << "\n";
	cout << "BFS: ";
	BFS(root);
	cout <<endl<< "IDDFS: ";
	frn(i, 5) {
		IDDFS(root, i, 0);
	}

	cout << "\n" << "Height: " << GetHeight(root) << endl;

	//cin >> n;
	return 0;
}