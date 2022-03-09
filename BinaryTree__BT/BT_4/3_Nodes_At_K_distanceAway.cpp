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


// case 1 - Nodes at subtree (downwards)
void PrintSubtreeNodes(struct Node* root , int k)  //here the root is the target node
{
    if(root == NULL  || k<0)
    {
        return ;
    }
    if(k == 0)  // you reached the node which is k distance away from the target
    {
        cout<<root->data<<" ";
    }

    PrintSubtreeNodes(root->left , k-1);
    PrintSubtreeNodes(root->right , k-1);
}


// case 2 - nodes at ancestor part (upward part)
int PrintNodeAtK(Node* root, Node* target , int k)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root == target)  // then there is no anscestor part..only downward subtree part
    {
        PrintSubtreeNodes(root , k);  // so print nodes at subtree part 
        return 0;   // hence the difference between the root and the target is 0...
    }


   
   //check the leftsubtree whether the target is present ot not
    int dl = PrintNodeAtK(root->left , target, k);  // here dl  is the diffrence between root's left child and target
    if(dl != -1)
    {
        if(dl + 1 == k)   // if root is k distance away from target(upward part)
        {
            cout<<root->data<<" ";
        }
        else  // check in the right subtree part
        {
            PrintSubtreeNodes(root->right , k-dl-2);
        }

        return dl+1;  // this function returns difference between root and target (hence dl contains the difference between root's left child and target...so +1 with that)
    }


    //check the rightsubtree whether the target is present ot not
    int dr = PrintNodeAtK(root->right, target, k);  // here dl  is the diffrence between root's right child and target
    if(dr != -1)
    {
        if(dr + 1 == k)   // if root is k distance away from target(upward part)
        {
            cout<<root->data<<" ";
        }
        else  // check in the left subtree part
        {
            PrintSubtreeNodes(root->left , k-dr-2);
        }

        return dr+1;  // this function returns difference between root and target (hence dl contains the difference between root's right child and target...so +1 with that)
    }


    return -1;  //target not find in the lefts subtree and right subtree

}



int main()
{
    struct Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
   
    root->right->right = new Node(6);

    /*    4                      
        /  \                                         
       9     5                                        
      / \     \                                        
     1   3     6                                        
                                               
    */
            //  root    target     k          // nodes which are k  1 distance away from root->left
   PrintNodeAtK(root , root->left , 1) ; // o/p is 1,3,4


    return 0;

}
