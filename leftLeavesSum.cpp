/* Given a tree, finding the sum of left leaves */
#include<iostream>
using namespace std;
struct node
{
	struct node * left;
	int data;
	struct node * right;
};
node * newnode(int val)
{
	node * n1 = new node;
	n1->left = NULL;
	n1->data = val;
	n1->right = NULL;
	return n1;
}
bool isleaf(struct node * n1)
{
	if(n1==NULL)
		return false;
	else if(n1->right == NULL && n1->left == NULL)
		return true;
	return false;
}
int lleaves(struct node * root)
{
	int res=0;
	if(root==NULL)
		return 0;
	else
	{
		if(isleaf(root->left))
			res += root->left->data;
		else
			res += lleaves(root->left);
		res+= lleaves(root->right);

	}
	return res;
}
int main()
{
	struct node * root = newnode(20);
	root->left = newnode(9);
	root->right = newnode(49);
	root->right->left = newnode(23);
	root->right->right = newnode(52);
	root->right->right->left = newnode(50);
	root->left->left = newnode(5);
	root->left->right = newnode(12);
	root->left->right->right = newnode(12);

	int result = lleaves(root);
	cout<<"sum is : "<<result;
	return 0;
}
