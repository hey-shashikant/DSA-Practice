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

vector<int> bottomview(node* root)
{
	vector<int>res;
	if(root == nullptr)
		return {};
	map<int,int>mp;
	queue<pair<int,node*>>q;
	q.push({0,root});
	while(!q.empty())
	{
		node* t = q.front().second;
		int x = q.front().first;
		q.pop();
		mp[x] = t->data;
		if(t->left)
		{
			q.push({x-1,t->left});
		}
		if(t->right)
		{
			q.push({x+1,t->right});
		}
	}
	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		res.push_back(it->second);
	}
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
	vector<int>v = bottomview(root);
	for(auto it : v)
		cout << it << " ";
	cout << "\n";
	return 0;
}