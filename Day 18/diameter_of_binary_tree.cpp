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

int diameter(node* root)
{
	if(root == nullptr)
		return 0;
	int left_height = height(root->left);
	int right_height = height(root->right);

	int left_diameter = diameter(root->left);
	int right_diameter = diameter(root->right);
	return max(1 + left_height + right_height , max(left_diameter,right_diameter));
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
	cout << "\n Diameter Of Binary Tree : ";
	cout << diameter(root);
	return 0;
}