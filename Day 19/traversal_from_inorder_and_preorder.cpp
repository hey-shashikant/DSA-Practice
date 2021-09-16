#include <bits/stdc++.h>
using namespace std;
int idx = 0;

struct node{
	int data;
	node* left;
	node* right;
	node(int x)
	{
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

int findindex(vector<int> &arr, int start, int end, int key)
{
	for(int i=start; i<=end; i++)
	{
		if(arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}

node* solve(vector<int>& preorder, vector<int> &inorder, int start, int end)
{
	if(start > end)
	{
		return nullptr;
	}
	node* root = new node(preorder[idx++]);
	if(start == end)
	{
		return root;
	}
	int index = findindex(inorder,start,end,root->data);
	root->left = solve(preorder,inorder,start,index-1);
	root->right = solve(preorder,inorder,index+1,end);
	return root;
}

node* buildTree(vector<int> &preorder, vector<int> &inorder)
{
	int sz = inorder.size();
	return solve(preorder, inorder, 0, sz-1);
}

void PreOrderTraversal(node* root)
{
	if(root == nullptr)
	{
		return;
	}
	cout << root->data << " ";
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}

int main()
{
	vector<int>preorder;
	vector<int>inorder;
	int num;
	cout << "\n Enter the number of nodes : ";
	cin >> num;
	cout << "\n Enter the preorder traversal : ";
	for(int i=0; i<num; i++)
	{
		int x;
		cin >> x;
		preorder.push_back(x);
	}
	cout << "\n Enter the inorder traversal : ";
	for(int i=0; i<num; i++)
	{
		int x;
		cin >> x;
		inorder.push_back(x);
	}
	node* root = buildTree(preorder,inorder);
	cout << "\n Preorder Traversal of the generated Tree : ";
	PreOrderTraversal(root);
	return 0;
}