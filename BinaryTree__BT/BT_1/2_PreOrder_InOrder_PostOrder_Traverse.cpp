#include<iostream>
using namespace std;

struct  Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    
};

void Preorder(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }
       
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}




int main()
{
    struct Node* root = new Node(1);
    root->left  = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);
     /* 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

     */

    Preorder(root);   cout<<endl;
    Inorder(root);    cout<<endl;
    Postorder(root);  cout<<endl;

    return 0;
}