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

void levelOrderTraversal(node* root)
{
	vector<int>v;
	if(root == nullptr)
		return;
	queue<node*>q;
	q.push(root);
	vector<int>temp;
	int ctr = 0;
	while(!q.empty())
	{
		ctr++;
		int sz = q.size();
		for(int i = 0; i < sz; i++)
		{
			node* t = q.front();
			//cout << t->data << " ";
			temp.push_back(t->data);
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
		if(ctr%2 != 0)
		{
			reverse(temp.begin(),temp.end());
		}
		for(auto it : temp)
		{
			v.push_back(it);
		}
		temp.clear();
	}
	for(auto it : v)
		cout << it <<  " ";
	cout << endl;
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
	cout << "\n Level order traversal : ";
	levelOrderTraversal(root);
	return 0;
}