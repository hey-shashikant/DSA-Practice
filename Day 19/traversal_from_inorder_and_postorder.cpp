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

node* solve(vector<int>& postorder, vector<int> &inorder, int start, int end)
{
	if(start > end)
	{
		return nullptr;
	}
	node* root = new node(postorder[idx--]);
	if(start == end)
	{
		return root;
	}
	int index = findindex(inorder,start,end,root->data);
	root->right = solve(postorder,inorder,index+1,end);
	root->left = solve(postorder,inorder,start,index-1);
	return root;
}

node* buildTree(vector<int> &postorder, vector<int> &inorder)
{
	int sz = inorder.size();
	return solve(postorder, inorder, 0, sz-1);
}

void PostOrderTraversal(node* root)
{
	if(root == nullptr)
	{
		return;
	}
	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	cout << root->data << " ";
}

int main()
{
	vector<int>postorder;
	vector<int>inorder;
	int num;
	cout << "\n Enter the number of nodes : ";
	cin >> num;
	idx = num-1;
	cout << "\n Enter the postorder traversal : ";
	for(int i=0; i<num; i++)
	{
		int x;
		cin >> x;
		postorder.push_back(x);
	}
	cout << "\n Enter the inorder traversal : ";
	for(int i=0; i<num; i++)
	{
		int x;
		cin >> x;
		inorder.push_back(x);
	}
	node* root = buildTree(postorder,inorder);
	cout << "\n Postorder Traversal of the generated Tree : ";
	PostOrderTraversal(root);
	return 0;
}