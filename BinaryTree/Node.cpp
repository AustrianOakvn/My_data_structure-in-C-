#include"pch.h"
#include"Node.h"
void btree::inorder_print() {
	inorder_print(root);
}
void btree::postorder_print() {
	postorder_print(root);
}
void btree::preorder_print() {
	preorder_print(root);
}
void btree::destroy_tree() {
	destroy_tree(root);
}
node* btree::search(const int value) {
	return search(value, root);
}
void btree::insert(const int value) {
	if (root != 0)
		insert(value, root);
	else
		root = NewNode(value);
}

