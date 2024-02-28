# Binary Tree

In this assignment you will continue the project we started in the learning
activity and finish the binary tree.  You will add a delete method.  One easy
logic for coding the delete method is the following:

+ Find the node you wish to delete
+ If the left pointer is null, replace the node with the right branch
+ else If the right pointer is null, replace the node with the left branch
+ Otherwise, replace the node's value with the value in the rightmost node of the left branch and remove the rightmost node on the left branch.

## Goals:

The purpose of this project is to continue working with C++ classes, practice working with templates, and understand and implement the concepts of the binary tree data structure.

## Requirements:

This class creates and manages the binary tree using template syntax.  The
easiest way to code a binary tree is through the use of recursion, but it will
not be tested if that is used or not.

At a minimum you must implement the following public methods:
+ BTree(); //Constructor: Creates an empty tree
+ ~BTree(); //Destructor: Deallocates memory
+ void insert(Type data); //Inserts a node into the tree
+ void preOrder(); //Displays a pre-order traversal of the tree
+ void inOrder(); //Displays an in-order traversal of the tree
+ void postOrder(); //Displays a post-order traversal of the tree
+ int nodeCount(); //Calculates the number of items in the tree
+ Node<Type>*find(Type item); //Returns a node that contains the given value
+ Node<Type>*findRightMostNode(Node<Type> *find);//Given the *find node, it traverses the tree to find the right most node from that branch.
+ void remove(Type item);//Removes the node from the tree
