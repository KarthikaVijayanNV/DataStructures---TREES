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
        right = NULL;
    }
};

Node* BuildtBST(Node* root , int val)
{
    if(root == NULL)
    {
        return new Node(val);   // If root is NULL..make a node with "val" and then return
    }

    if(val < root->data) 
    {
        root->left = BuildtBST(root->left , val);
    }
    else  // if value is greater ..then right subtree
    {
        root->right = BuildtBST(root->right , val);
    }

    return root;

}

// Inorder function ..for checking

void PrintInorder(Node* root)
{
    if( root == NULL)
    {
        return ;
    }

    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}


int main()
{
    /* 
         Array given Initially is = 5,1,3,4,2,7
    
            5
          /   \
         1     7  
          \     
           3
          /  \
         2    4       if this BST is printed Inorder = 1,2,3,4,5,7   (sorted   :   by default)

     */


    struct Node* root = NULL;
    root = BuildtBST(root , 5);   // a root is created with 5

    BuildtBST(root , 1);
    BuildtBST(root , 3);
    BuildtBST(root , 4);
    BuildtBST(root , 2);
    BuildtBST(root , 7);


    // Pint Inorder and check..whether it's correct ot not
    PrintInorder(root);

    
}  
