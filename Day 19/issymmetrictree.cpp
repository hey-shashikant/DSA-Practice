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

bool solve(node* t1 , node* t2)
{
	if(t1 == nullptr or t2 == nullptr)
	{
		if(t1 == nullptr and t2 == nullptr)
		{
			return true;
		} 
		else
		{
			return false;
		}
	}
	if(t1->data == t2->data)
	{
		return (solve(t1->left,t2->right) and solve(t1->right,t2->left));
	}
	return false;
}

bool isSymmtericTree(node* root)
{
	if(root == nullptr)
		return true;
	if(root->left == nullptr and root->right == nullptr)
		return true;
	return solve(root,root); 
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
	if(isSymmtericTree(root))
		cout << "\n The given binary tree is symmetric.";
	else
		cout << "\n The given binary tree is not symmetric.";
	return 0;
}