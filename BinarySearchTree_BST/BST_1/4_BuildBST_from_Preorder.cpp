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


void PrintPreorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root->data <<" ";
    PrintPreorder(root->left);
    PrintPreorder(root->right);
}

//Build BST preorder sequence

Node* BuildBST(int preorder[] , int* preorderIdx , int key , int Min , int Max, int n)
{

    if(*preorderIdx >= n )
    {
        return NULL;
    }

    Node* root = NULL;
    if(key > Min && key < Max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx +1;

        if(*preorderIdx < n)
        {
            root->left = BuildBST(preorder , preorderIdx , preorder[*preorderIdx] , Min, key, n);
        }
        if(*preorderIdx < n)
        {
            root->right = BuildBST(preorder, preorderIdx , preorder[*preorderIdx], key , Max , n);
        }
    }
    return root;
}







int main()
{
    /* 
       Binary Search Tree
            10
           / \
          2   13
         /    /
        1    11

       preorder[] = {10,2,1,13,11}

     */

    int preorder[] = {10,2,1,13,11};
    int preorderIdx = 0;
    int n = 5;
    // getting the ans into a root 
    Node* root = BuildBST(preorder, &preorderIdx , preorder[0], INT_MIN , INT_MAX, n);

    // after building BST using preorder  ...checking whether it is build correct or not

    PrintPreorder(root);  // o/p should be the preorder sequence given already

   
    return 0;
}