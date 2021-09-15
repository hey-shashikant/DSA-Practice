/*
A tree is said to be balanced if all the subtree of all nodes has a height difference of one
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
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


int height(node* root)
{
	if(root == nullptr)
		return 0;
	int left_height = height(root->left);
	int right_height = height(root->right);
	return 1 + max(left_height,right_height);
}

bool isbalanced(node* root)
{
	if(root == nullptr)
		return true;
	int l = height(root->left);
	int r = height(root->right);
	int x = abs(l-r);
	if(x <= 1 and isbalanced(root->left) and isbalanced(root->right))
		return true;
	return false;
}

int main()
{
	int x;
	cout << "\n Enter root : ";
	cin >> x;
	node* root = new node(x);
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* t = q.front();
		q.pop();
		int l,r;
		cout << "\n Enter left child of " << t->data << " : ";
		cin >> l;
		if(l != -1)
		{
			node* temp = new node(l);
			t->left = temp;
			q.push(temp);
		}
		cout << "\n Enter right child of " << t->data << " : ";
		cin >> r;
		if(r != -1)
		{
			node* temp = new node(r);
			t->right = temp;
			q.push(temp);
		}
	}
	if(isbalanced(root))
		cout << "\n Binary tree is balanced.";
	else
		cout << "\n Binary tree is not balanced.";
	return 0;
}