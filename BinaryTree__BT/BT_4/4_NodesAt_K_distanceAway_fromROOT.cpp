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


// Nodes which are k distance away from the main root node
void PrintSubtreeNodes(struct Node* root , int k)  
{
    if(root == NULL  || k<0)
    {
        return ;
    }
    if(k == 0)  // you reached the node k distance away from root
    {
        cout<<root->data<<" ";
    }

    PrintSubtreeNodes(root->left , k-1);
    PrintSubtreeNodes(root->right , k-1);
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

    PrintSubtreeNodes(root,2);  // Nodes at 2 distance away from root node(4)  is
                                // o/p = 1,3,6

    return 0;

}
