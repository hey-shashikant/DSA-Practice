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

void PreOrder(node* root)
{
	if(root == nullptr)
		return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void IterativePreorder(node* root)
{
	stack<node*>stk;
	while(stk.size() > 0 or root != nullptr)
	{
		if(root != nullptr)
		{
			stk.push(root);
			cout << root->data << " ";
			root = root->left;
		}
		else
		{
			node* t = stk.top();
			stk.pop();
			root = t->right;
		}
	}
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
	cout << "\n Pre-order traversal : ";
	PreOrder(root);
	cout << "\n Iterative Pre-order traversal : ";
	IterativePreorder(root);
	return 0;
}