#include<iostream>
using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right ;

    Node(int val)
    {
        data = val;
        left =NULL;
        right = NULL;
    }
};

// sum replacement 
void sumReplace(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left != NULL)
    {
        root->data += root->left->data;
    }
    if(root->right != NULL)
    {
        root->data += root->right->data;
    }
}
// checking by printing preorder series
void PreorderPrint(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    PreorderPrint(root->left);
    PreorderPrint(root->right);
}




int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*    1                          28        
        /  \                        /  \
       2    3                      11    16        
      / \   / \                   / \   / \
     4   5 6   7                 4   5 6   7 
         
                                    after sum replacement 
    before            
    preorder = 1,2,4,5,3,6,7        preorder = 28,11,4,5,16,6,7

    */
     
    // before sum replacement
    PreorderPrint(root);
    //sum repalcement
    sumReplace(root);      cout<<endl;  // tree replaced   

    //again calling preorder print 
    PreorderPrint(root);


   
    return 0;
}
