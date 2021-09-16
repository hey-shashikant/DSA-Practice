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


bool isSameTree(node* t1, node* t2)
{
	if(t1 == nullptr or t2 == nullptr)
	{
		if(t1 == nullptr and t2 == nullptr)
			return true;
		else
			return false;
	}
	if(t1->data == t2->data)
	{
		return (isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right));
	}
	return false;
}

int main()
{
	int x;
	cout << "\n Enter root 1 : ";
	cin >> x;
	node* t1 = new node(x);
	queue<node*>q1;
	q1.push(t1);
	while(!q1.empty())
	{
		node* t = q1.front();
		q1.pop();
		int l,r;
		cout << "\n Enter left child of " << t->data << " : ";
		cin >> l;
		if(l != -1)
		{
			node* temp = new node(l);
			t->left = temp;
			q1.push(temp);
		}
		cout << "\n Enter right child of " << t->data << " : ";
		cin >> r;
		if(r != -1)
		{
			node* temp = new node(r);
			t->right = temp;
			q1.push(temp);
		}
	}

	int y;
	cout << "\n Enter root 2 : ";
	cin >> y;
	node* t2 = new node(y);
	queue<node*>q2;
	q2.push(t2);
	while(!q2.empty())
	{
		node* t = q2.front();
		q2.pop();
		int l,r;
		cout << "\n Enter left child of " << t->data << " : ";
		cin >> l;
		if(l != -1)
		{
			node* temp = new node(l);
			t->left = temp;
			q2.push(temp);
		}
		cout << "\n Enter right child of " << t->data << " : ";
		cin >> r;
		if(r != -1)
		{
			node* temp = new node(r);
			t->right = temp;
			q2.push(temp);
		}
	}

	if(isSameTree(t1,t2))
		cout << "\n Both trees are same.";
	else
		cout << "\n Both trees are different.";
	return 0;
}