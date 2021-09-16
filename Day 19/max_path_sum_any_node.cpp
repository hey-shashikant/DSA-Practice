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

int solve(node* root, int &res)
{
	if(root == nullptr)
		return 0;
	int left = solve(root->left,res);
	int right = solve(root->right,res);

	int maxi = max(left,right);
	int m1 = max(root->data+maxi,root->data);
	int m2 = max(root->data + left + right, m1);
	res = max(res,m2);
	return m1;
}

int maxpathsum(node* root)
{
	int res = INT_MIN;
	solve(root,res);
	return res;
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
	cout << "\n Maximum path sum between any two nodes : ";
	cout << maxpathsum(root);
	return 0;
}