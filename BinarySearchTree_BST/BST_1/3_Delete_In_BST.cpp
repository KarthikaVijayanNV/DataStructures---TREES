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

// Inorder function for checking
void InorderPrint(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    InorderPrint(root->left);
    cout<<root-> data << " ";
    InorderPrint(root->right);

}


// function to fing InorderSuccessor
Node* InorderSuccessor(Node* root)
{
    Node* curr = root;
    while(curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;   // that will be your successor
}




Node* DeleteInBST(Node* root , int key)
{
    if(key < root-> data)
    {
        root->left = DeleteInBST(root->left , key);
    }
    else if( key > root->data )
    {
        root->right = DeleteInBST(root->right , key);
    }

    // root->data ==key    key kittii    then 3 cases are there to consider
    else
    {
        // case 1 and case 2 can be together handled
        if(root->left == NULL)
        {
            Node* temp = root->right ;
            free(root);
            return temp;
        }
        else if( root->right == NULL) // mirror of the previous condition
        {
            Node* temp = root->left ;
            free(root);
            return temp;
        }
         //by default n..... case 3     2 children is present
        
        Node*  temp = InorderSuccessor(root->right);
        root->data = temp->data;
        root->right = DeleteInBST(root->right , temp->data);        
    }

    return root;
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

    // print inorder and check 
    InorderPrint(root);     // 1,2,3,4,5,6

    // delete one node
    DeleteInBST(root, 2);   cout<<endl;

    //again call inorder and check whether 2 is deleted or not
    InorderPrint(root);  // 1,3,4,5,6
    
   
    return 0;
}