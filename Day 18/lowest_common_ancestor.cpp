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

node* LowestCommonAncestor(node* root, int p, int q)
{
	if(root == nullptr or root->data == p or root->data == q)
		return root;
	node* left = LowestCommonAncestor(root->left, p, q);
	node* right = LowestCommonAncestor(root->right,p,q);
	if(left == nullptr)
		return right;
	else if(right == nullptr)
		return left;
	else
		return root;
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
	int p1,q1;
	cout << "\n Enter the two nodes whose lowest common ancestor you want to find : ";
	cin >> p1 >> q1;
	cout << "\n Lowest Common Ancestor is : ";
	node* t = LowestCommonAncestor(root,p1,q1);
	cout << t->data;
	return 0;
}