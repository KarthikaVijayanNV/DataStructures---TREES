#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right= NULL;
    }

};


//search in BST
Node* SearchInBST(Node* root , int key)
{

   if(root == NULL)
   {
       return NULL;
   }

    if(key == root->data)
    {
        return root;
    }
    if(key < root->data)
    {
        return SearchInBST(root->left , key);
    }

    // then by default key > root->data, then search in right subtree

   return SearchInBST(root->right , key);
}





int main()
{
    /* 
       Binary Search Tree
            4
           / \
          2   5
         / \   \
        1   3   6

     */

    struct Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    
    
    //Search 
    if(SearchInBST(root , 5) == NULL )
    {
        cout<<"Key doesn't exist"<<endl;
    }
    else
    {
        cout<<"Key exist"<<endl;
    }

    return 0;
}