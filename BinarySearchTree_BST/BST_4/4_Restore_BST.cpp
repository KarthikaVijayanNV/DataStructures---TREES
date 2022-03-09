#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node( int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


//Inorder printing   for checking the BST
void Inorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    Inorder(root->left);
    cout<<root->data <<" ";
    Inorder(root->right);
}




// swap function
void swap(int* a, int* b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}




void CalcPointers(Node* root , Node** first, Node**mid, Node** last, Node** prev)
{
    if(root ==NULL)
    {
        return;
    }
    // coding in   "Inorder Fashion"   calling (leftsubtree   and then  rightsubtree)

    CalcPointers(root->left , first, mid, last , prev);

    // if somewhere the rule is violated or not
    if(*prev && root->data < (*prev)->data)
    {
        // if it is violated for the 1st time or not
        if(! *first)
        {
            *first = *prev;
            *mid = root;
        }
        else // not first time
        {
            *last = root;
        }
    }
     
    // before calling right subtree
    *prev = root;   // previous become new root for traversing rightsubTree
    CalcPointers(root->right , first , mid, last , prev);

}

void restoreBST(Node* root)
{
    Node* first , *mid , *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    CalcPointers(root , &first, &mid, &last, &prev);  // calling this function ,after this function
                                        // pointers will be got values

    if(first && last)  //case 1
    {
        swap(&(first->data) , &(last->data));
    }
    else if(first && mid)   //case 2
    {
        swap(&(first->data), &(mid->data));
    }

}



int main()
{

  /*
        violated BST

          6
        /  \
       9    3             9 & 3 are swapped 
     /  \
    1    4
        
  */

    struct Node* root= new Node(6);
    root->left = new Node(9);
    root->right =new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);


    // call inorder print initially
    Inorder(root);       // 1 9 4 6 3
    cout<<endl;

    restoreBST(root);   // prop restored   ....correcetd (element swapped correctly)

    Inorder(root);    //1 3 4 6 9      correct sorted order means  BST restored correclty
    cout<<endl;


    return 0;
}