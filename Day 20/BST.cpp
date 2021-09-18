#include<bits/stdc++.h>
using namespace std;

//Structure of Node
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data = x;
		left = right = nullptr;
	}
};

//Insertion in BST
Node* insert(Node* root, int key)
{
	Node* t = nullptr;
	Node* temp = root;
	while (temp != nullptr)
	{
		t = temp;
		if(temp->data == key)
			return root;
		else if(temp->data < key)
			temp = temp->right;
		else
			temp = temp->left;
	}
	Node* ptr = new Node(key);
	if(t->data < key)
		t->right = ptr;
	else
		t->left = ptr;
	return root;
}

Node* searchNode(Node* root, int key)
{
	while(root != nullptr)
	{
		if(root->data == key)
			return root;
		else if(root->data < key)
			root = root->right;
		else
			root = root->left;
	}
	return nullptr;
}

//Inorder Traversal.
void Inorder(Node* root)
{
	if(root == nullptr)
		return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

//Driver Program
int main()
{
	int n;
	cout << "\n Enter the number of nodes : ";
	cin >> n;
	cout << "\n Enter the nodes of the BST : ";
	int p;
	cin >> p;
	Node* root = new Node(p);
	for(int i=0; i<n-1; i++)
	{
		int x;
		cin >> x;
		root = insert(root,x);
	}
	cout << "\n Inorder traversal of BST : ";
	Inorder(root);
	cout << "\n Enter the key element to be searched : ";
	int key;
	cin >> key;
	Node* t = searchNode(root,key);
	if(t == nullptr)
		cout << "\n Element not found.";
	else
		cout << "\n Element found.";
	return 0;
}