#include<iostream>
using namespace std;

int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
int id = 0;

struct Node {
	int val;
	Node * left, *right;
};

void preOrder(Node *x) {
	if (x)		//或者写if(x==NULL)return; 
	{
		cout << x->val<<'!';
		preOrder(x->left);
		preOrder(x->right);
	}
}
//inOrder
//postOrder
//用queue进行按层遍历

void createTree(Node* &root) {
	//参数是Node指针的引用，通过引用可以改变传入的指针
	if (id > 7)return;
	root = new Node();//指针等于新指针
	root->val = ::data[id++];
	createTree(root->left);
	createTree(root->right);
}

int main() {
	Node* root;//指针
	createTree(root);
	preOrder(root);
	system("pause");
}