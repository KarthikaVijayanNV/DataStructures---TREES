#include<iostream>
#include<climits>
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

bool isBST(Node* root , Node* Min =NULL , Node* Max = NULL)
{
    if(root == NULL)
    {
        return true;
    }

    if(Min != NULL   &&  root->data <= Min->data)
    {
        return false;
    }

    if(Max != NULL && root->data >= Max->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left , Min , root);
    bool rightVaid = isBST(root->right , root, Max);

    return leftValid and rightVaid ; 
}






int main()
{
    /* 
       BST - 1

            1
           / \
          2   3     Not valid BST

     */

    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
      

     /* 
       BST - 2

            5
           / \
          3   8      valid BST

     */

    Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(8);  




    if(isBST(root2, NULL, NULL))   // change the root1 to root2  and check
    {
        cout<<"Valid BST"<<endl;
    }  
    else
    {
        cout<<"Invalid BST"<<endl;
    }


    cout<<endl;

    return 0;
}