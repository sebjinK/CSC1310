#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

class BST
{
	private:
		struct treeNode
		{
			int value;
			treeNode* left;
			treeNode* right;
		};
		treeNode* root;
	//				used to 
		void copy(treeNode*& destination, treeNode* copyInput)
		{
			if (!copyInput)
			{
				destination = NULL; //make copied tree = null
			}
			else
			{
				destination = new treeNode;
				destination->value = copyInput->value;
				destination->left = destination->right = NULL;
				/*
				treeNode * newNode = new treeNode;
				newNode->value = copyInput->value;
				newNode->left = newNode->right = NULL;
				*/
				insert(destination, copyInput);				
				//if (copyInput->left)
				copy(destination->left, copyInput->left);
				//if (copyInput->right)
				copy(destination->right, copyInput->right);
			}
			
		}
		void insert(treeNode*& destination, treeNode* input)
		{
			if (destination == NULL)
				destination = input;
			else if (input->value < destination->value)
				insert(destination->left, input);
			else
				insert(destination->right, input);
		}
		void displayInOrder(treeNode* node) const
		{
			if (node)
			{
				displayInOrder(node->left); //will recursively cycle through every node on the left side
				cout << node->value << " ";
				displayInOrder(node->right);//will recursively cycle through every node on the right side
			}
		}
		void destroySubTree(treeNode* node)
		{
			if (node)
			{
				if (node->left)
					destroySubTree(node->left);
				if(node->right)
					destroySubTree(node->right);
				delete node;
			}
		}

	public:
		BST()
		{
			root = NULL;		
		}	//default constructor
		BST(const BST &tree)
		{
			copy(root, tree.root);
		}	//copy constructor
		~BST()
		{
			destroySubTree(root);
		}

		void insertNode(int num)
		{
			treeNode * newNode = new treeNode;
			newNode->value = num;
			newNode->left = newNode->right = NULL;

			insert(root, newNode);
		}
		void display()
		{
			displayInOrder(root);
		}
};

#endif