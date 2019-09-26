#pragma once
#include<iostream>
struct node {
	int value;
	node *left;
	node *right;
};

class btree {
private:
	node* root;
public:
	btree() :root(0) {};
	~btree() {
		destroy_tree();
	}

	node*NewNode(const int value) {
		node*temp = (node*)malloc(sizeof(node));
		temp->value = value;
		temp->left = temp->right = 0;
		return temp;
	}
	void insert(const int value);
	node *search(const int value);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();
private:
	void destroy_tree(node *leaf) {
		if (leaf != 0) {
			destroy_tree(leaf->left);
			destroy_tree(leaf->right);
			delete leaf;
		}
	}
	/*void insert(type value, node *leaf) {
		if (value < leaf->value) {
			if (leaf->left != 0)
				insert(value, leaf->left);
			else {
				leaf->left = new node;
				leaf->left->value = value;
				leaf->left->left = 0;
				leaf->left->right = 0;
			}
		}
		else if (key >= leaf->value) {
			if (leaf->right != 0)
				insert(value, leaf->right);
			else {
				leaf->right = new node;
				leaf->right->value = value;
				leaf->right->left = 0;
				leaf->right->right = 0;
			}
		}
	}*/
	node *search(int value, node *leaf) {
		if (leaf == 0 || leaf->value == value)
			return leaf;
		if (leaf->value < value)
			return search(value, leaf->right);
		return search(value, leaf->left);
	}
	void inorder_print(node *leaf) {
		if (leaf != 0) {
			inorder_print(leaf->left);
			std::cout << leaf->value << std::endl;
			inorder_print(leaf->right);
		}
	}
	void postorder_print(node *leaf) {
		if (leaf != 0) {
			inorder_print(leaf->left);
			inorder_print(leaf->right);
			std::cout << leaf->value << std::endl;
		}

	}
	void preorder_print(node *leaf) {
		if (leaf != 0) {
			std::cout << leaf->value << std::endl;
			inorder_print(leaf->left);
			inorder_print(leaf->right);
		}
	}
	node* insert(int value, node* leaf) {
		if (leaf == 0) 
			return NewNode(value);
		if (value < leaf->value)
			leaf->left = insert(value, leaf->left);
		else if (value > leaf->value)
			leaf->right = insert(value, leaf->right);
		return leaf;
	}
};
