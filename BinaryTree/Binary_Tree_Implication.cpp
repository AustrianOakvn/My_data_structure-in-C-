// Binary_Tree_Implication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include"Node.h"
using namespace std;

int main()
{
	btree mytree;
	mytree.insert(50);
	mytree.insert(30);
	mytree.insert(20);
	mytree.insert(40);
	mytree.insert(70);
	mytree.insert(60);
	mytree.insert(80);
	mytree.inorder_print();
	mytree.search(10);
	cout << mytree.search(10) << endl;
    std::cout << "Hello World!\n"; 
}

