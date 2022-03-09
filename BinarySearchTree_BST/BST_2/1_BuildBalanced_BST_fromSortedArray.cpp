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

    cout<<root->data<<" ";
    PrintPreorder(root->left);
    PrintPreorder(root->right);

}

// using Binary Search approach to build Balanced BST from sorted
Node* SortedArrayToBST(int arr[] , int start , int end)
{
    if(start > end)
    {
        return NULL;
    }

    int mid  = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = SortedArrayToBST(arr, start, mid-1);
    root->right = SortedArrayToBST(arr , mid+1 , end);

    return root;
}

// after this a balanced tree is build


int main()
{
   // sorted array is given
    int arr[] = {10,20,30,40,50};   // total n =5    end is given as 4
    Node* root = SortedArrayToBST(arr, 0, 4); 

    // a Balanecd BST is build  ...it will look like 

    /* 
       Balance BST 

            30
           / \
          10  40    
           \    \
           20   50
                     preorder sequence will be   =  30,10,20,40,50
     */

    PrintPreorder(root);     //  o/p should be the same given above
    
    return 0;
}