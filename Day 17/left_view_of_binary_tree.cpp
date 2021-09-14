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

vector<int> leftview(node* root)
{
	vector<int>v;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node* x = q.front();
		v.push_back(x->data);
		int len = q.size();
		for(int i=0; i<len; i++)
		{
			node* t = q.front();
			q.pop();
			if(t->left)
			{	
				q.push(t->left);
			}
			if(t->right)
			{
				q.push(t->right);
			}
		}
	}
	return v;
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
	cout << "\n Left view of binary tree : ";
	vector<int>v = leftview(root);
	for(auto it : v)
		cout << it << " ";
	cout << "\n";
	return 0;
}