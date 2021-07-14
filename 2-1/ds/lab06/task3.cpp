#include <bits/stdc++.h>
#include <dbg.h>
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
	if(!u)
		return;

	dfs(u->left);
	printf("%d(%d) ", u->val, balance_factor(u));
	dfs(u->right);
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
		right_rotate(u, root);
	}
	else if(bf > 1 and key > u->left->val) {
		left_rotate(u->left, root);
		right_rotate(u, root);
	}
	else if(bf < 1 and key < u->left->val) {
		right_rotate(u->right, root);
		left_rotate(u, root);
	}
	else{
		left_rotate(u, root);
	}
}

void insert(int key, node* &root)
{
	if(!root) {
		root = create(key);
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

	itr = newNode;
	while(itr) {
		int bf = balance_factor(itr);
		
		if(bf < -1 or bf > 1) {
			balance(itr, bf, key, root);
			break;
		}
		itr = itr->parent;
	}
}

int lca(node* u, int n1, int n2) {
	if(!u)
		return -1;

	dbg(u->val);

	if(u->val > n1 and u->val > n2)
		return lca(u->left, n1, n2);

	else if(u->val < n1 and u->val < n2)
		return lca(u->right, n1, n2);

	return u->val;
}


int main()
{
	int x, tc, n1, n2;
	node* root = NULL;
	while(cin >> x and x != -1){
		insert(x, root);
	}

	printf("Final Status: ");
	dfs(root);

	cin >> tc;
	while(tc--) {
		cin >> n1 >> n2;
		cout << lca(root, n1, n2) << "\n";
	}
}