#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;

struct node{
	int val, h;
	node* left;
	node* right;
	node* parent;
};

node* create(int key)
{
	node* newNode = new node();
	newNode->val = key;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->h = 0;
	return newNode;
}

int height(node *n) {
	return (n ? n->h : -1);
}

void update_height(node* u) {
	u->h = 1 + max(height(u->left), height(u->right));
}

int balance_factor(node* u) {
	return height(u->left) - height(u->right);
}

void dfs(node* u)
{
	stack <node*> s;
	node* cur = u;

	while(cur or s.size()){
		while(cur) {
			s.push(cur);
			cur = cur->left;
		}
		cur = s.top();
		s.pop();
		printf("%d(%d) ", cur->val, balance_factor(cur));
		cur = cur->right;
	}
}

void left_rotate(node* z, node* &root) {
	node* y = z->right;
	node* T = y->left;


	if(z == root) {
		root = y;
	} else {
		if(z == z->parent->right)
			z->parent->right = y;
		else
			z->parent->left = y;
	}


	y->parent = z->parent;
	y->left = z;
	z->parent = y;
	z->right = T;
	if(T)
		T->parent = z;

	node* itr = z;
	while(itr) {
		update_height(itr);
		itr = itr->parent;
	}
}

void right_rotate(node* z, node* &root) {
	node* y = z->left;
	node* T = y->right;

	if(z == root) {
		root = y;
	} else {
		if(z == z->parent->right) 
			z->parent->right = y;
		else
			z->parent->left = y;
	}

	y->parent = z->parent;
	y->right = z;
	z->parent = y;
	z->left = T;
	if(T)
		T->parent = z;


	node* itr = z;
	while(itr) {
		update_height(itr);
		itr = itr->parent;
	}
}

void balance(node* u, int bf, int key, node* &root) {
	if(bf > 1 and key < u->left->val) {
		puts("LL case");
		printf("Right rotate(%d)\n", u->val);
		right_rotate(u, root);
	}
	else if(bf > 1 and key > u->left->val) {
		puts("LR case");
		printf("Left rotate(%d), Right rotate(%d)\n", u->left->val, u->val);
		left_rotate(u->left, root);
		right_rotate(u, root);
	}
	else if(bf < 1 and key < u->left->val) {
		puts("RL case");
		printf("Right rotate(%d), Left rotate(%d)\n", u->right->val, u->val);
		right_rotate(u->right, root);
		left_rotate(u, root);
	}
	else{
		puts("RR case");
		printf("Left rotate(%d)\n", u->val);
		left_rotate(u, root);
	}

	printf("Status: ");
	dfs(root);
	puts("");
	printf("Root = %d\n", root->val);
}

void insert(int key, node* &root)
{
	
	if(!root) {
		root = create(key);
		dfs(root);
		printf("\n");
		puts("Balanced");
		printf("Root=%d\n", root->val);
		return;
	}

	node* temp = NULL;
	node* itr = root;

	while(itr) {
		temp = itr;
		if(key > itr->val){
			itr = itr->right;
		}
		else {
			itr = itr->left;
		}
	}

	node* newNode = create(key);
	if(key > temp->val)
		temp->right = newNode;
	else
		temp->left = newNode;
	newNode->parent = temp;
	
	itr = newNode->parent;
	while(itr) {
		update_height(itr);
		itr = itr->parent;
	}

	dfs(root);
	puts("");
	bool balanced = true;

	itr = newNode;
	while(itr) {
		int bf = balance_factor(itr);
		
		if(bf < -1 or bf > 1) {
			balanced = false;
			printf("Imbalance at node %d\n", itr->val);
			balance(itr, bf, key, root);
			break;
		}
		itr = itr->parent;
	}

	if(balanced) {
		puts("Balanced");
		printf("Root = %d\n", root->val);
	}
}


int main()
{
	int x;
	node* root = NULL;
	while(cin >> x and x != -1){
		insert(x, root);
		printf("\n\n");
	}
}