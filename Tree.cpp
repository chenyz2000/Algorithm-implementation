#include<iostream>
using namespace std;

int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
int id = 0;

struct Node {
	int val;
	Node * left, *right;
};

void preOrder(Node *x) {
	if (x)		//����дif(x==NULL)return; 
	{
		cout << x->val<<'!';
		preOrder(x->left);
		preOrder(x->right);
	}
}
//inOrder
//postOrder
//��queue���а������

void createTree(Node* &root) {
	//������Nodeָ������ã�ͨ�����ÿ��Ըı䴫���ָ��
	if (id > 7)return;
	root = new Node();//ָ�������ָ��
	root->val = ::data[id++];
	createTree(root->left);
	createTree(root->right);
}

int main() {
	Node* root;//ָ��
	createTree(root);
	preOrder(root);
	system("pause");
}