#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
using namespace std;

template <class Type>
struct Node {
    Type item;
    Node<Type> *left;
    Node<Type> *right;
};

template <class Type>
class BinaryTree
{
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(Type item);
        void preOrder();
        void inOrder();
        void postOrder();
        int nodeCount();
        Node<Type>*find(Type item);
        Node<Type>*findRightMostNode(Node<Type> *find);
        void remove(Type item);
        int  height();
        int leavesCount();


    protected:
        Node<Type> *root;

    private:
        void destroy(Node<Type> * curr);
        void insert(Type item, Node<Type> * curr);
        void preOrder(Node<Type> *curr);
        void postOrder(Node<Type> *curr);
        void inOrder(Node<Type> * curr);
        int nodeCount(Node<Type> * curr);
        int leavesCount(Node<Type> * curr);
        Node<Type>*find(Type item, Node<Type> *curr);
        Node<Type>* remove(Type item, Node<Type>*curr);
        int height(int level, Node<Type>*curr);
};

template <class Type>
BinaryTree<Type>::BinaryTree(){
    root = nullptr;
}

template <class Type>
BinaryTree<Type>::~BinaryTree(){
    destroy(root);
}

template <class Type>
void BinaryTree<Type>::destroy(Node<Type> * curr){
    if(curr != nullptr){
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }
}

template <class Type>
void BinaryTree<Type>::insert(Type item){
    if(root == nullptr){
        root = new Node<Type>;
        root->item = item;
        root->left = nullptr;
        root->right = nullptr;
    }
    else{
        insert(item, root);
    }

}

template <class Type>
void BinaryTree<Type>::insert(Type item, Node<Type> * curr){
    if(item < curr->item){
        if(curr->left == nullptr){
            auto tmp = new Node<Type>;
            tmp->item = item;
            tmp->left = nullptr;
            tmp->right = nullptr;
            curr->left = tmp;
        }else{
            insert(item, curr->left);
        }//ends inner if
    }//ends outer if
    else{
        if(curr->right == nullptr){
            auto tmp = new Node<Type>;
            tmp->item = item;
            tmp->left = nullptr;
            tmp->right = nullptr;
            curr->right = tmp;
        }else{
            insert(item, curr->right);
        }//ends inner if
    }
}


template <class Type>
void BinaryTree<Type>::preOrder(){
    cout << "Pre Order: ";
    preOrder(root);
}
template <class Type>
void BinaryTree<Type>::preOrder(Node<Type> *curr){
    if(curr){
        cout << curr->item << " ";
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

template <class Type>
void BinaryTree<Type>::inOrder(){
    cout << "In Order: ";
    inOrder(root);
}
template <class Type>
void BinaryTree<Type>::inOrder(Node<Type> *curr){
    if(curr){
        inOrder(curr->left);
        cout << curr->item << " ";
        inOrder(curr->right);
    }

}

template <class Type>
void BinaryTree<Type>::postOrder(){
    cout << "Post Order: ";
    postOrder(root);
}
template <class Type>
void BinaryTree<Type>::postOrder(Node<Type> *curr){
    if(curr){
        postOrder(curr->left);
        postOrder(curr->right);
        cout << curr->item << " ";
    }
}


template <class Type>
int BinaryTree<Type>::nodeCount(){
    return nodeCount(root);
}

template <class Type>
int BinaryTree<Type>::nodeCount(Node<Type> *curr){
    if(curr){
        return 1 + nodeCount(curr->left) + nodeCount(curr->right);
    }
    return 0;
}

template <class Type>
int BinaryTree<Type>::leavesCount(){
    return leavesCount(root);
}

template <class Type>
int BinaryTree<Type>::leavesCount(Node<Type> *curr){
    if(curr == nullptr){
        return 0;
    }
    if(curr->left == nullptr && curr->right == nullptr){
        return 1;
    }
    else{
        return leavesCount(curr->left) + leavesCount(curr->right);
    }
}


template <class Type>
Node<Type>*BinaryTree<Type>::find(Type item){
    return find(item, root);
}


template <class Type>
Node<Type>*BinaryTree<Type>::find(Type item, Node<Type>*curr){
    while(curr){
        if(item == curr->item){
            return curr;
        }else if(item < curr->item){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    return nullptr;
}


template <class Type>
Node<Type>*BinaryTree<Type>::findRightMostNode(Node<Type> *curr){
    //while current node
    while(curr){
        //if node is null, return
        if(curr == nullptr){
            return nullptr;
        }//else if next right is null, return current
        else if(curr->right == nullptr){
            return curr;
        }//else update
        else{
            curr = curr->right;
        }
    }
    //call recursive function to go to next node
    return findRightMostNode(curr);
}

template <class Type>
void BinaryTree<Type>::remove(Type item){
    remove(item, root);
}


template <class Type>
Node<Type>* BinaryTree<Type>::remove(Type item, Node<Type>* curr){

    Node<Type> *parent = nullptr;
    while(curr)//search for node
    {
        //node found
        if(curr->item == item){
            //remove leave
            if(curr->left == nullptr && curr->right == nullptr){
                if(parent == nullptr){ //node is root
                    root = nullptr;
                }else if(parent->left == curr){
                    parent->left = nullptr;
                }else{
                    parent->right = nullptr;
                }
            }//end if
            else if(curr->right == nullptr){ //remove node with only left child
                if(parent == nullptr){//node is root
                    root = curr->left;
                }else if(parent->left == curr){
                    parent->left = curr->left;
                }else{
                    parent->right = curr->right;
                }
            }//end else if
            else if(curr->left == nullptr){ //remove node with only yright child
                if(parent == nullptr){//node is root
                    root = curr->right;
                }else if(parent->left == curr){
                    parent->left = curr->right;
                }else{
                    parent->right = curr->right;
                }
            }//end else if
            else{//remove node with 2 children
                //find successor(leftmost child of right subtree)
                auto successor = curr->right;
                while(successor->left != nullptr){
                    successor = successor->left;
                }
                auto sucData = successor->item;
                remove(sucData);    //remove successor
                curr->item = sucData;
            }
            return curr; //node found and removed
        }//end if
        else if(curr->item < item){ //search right
            parent = curr;
            curr = curr->right;
        }else{//search left
            parent = curr;
            curr = curr->left;
        }
    }
    return nullptr;//node not found
}

template <class Type>
int BinaryTree<Type>::height(){
    return height(0, root);
}
template <class Type>
int BinaryTree<Type>::height(int level, Node<Type>*curr){
    //set heights to the given level
    int leftHeight = level;
    int rightHeight = level;
    //if curr is null, return
    if(curr == nullptr){
        return -1;
    }else{
        //recursive call for height, set to next level
        int leftHeight = height(leftHeight, curr->left);
        int rightHeight = height(rightHeight, curr->right);
        //return 1 + the max between the 2 given heights
        return 1 + max(leftHeight, rightHeight);
    }
}

#endif // BINARY_TREE_H
