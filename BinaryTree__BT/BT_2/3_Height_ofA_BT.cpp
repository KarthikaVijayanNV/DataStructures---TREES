#include<iostream>
#include<queue>
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

// finding the height of a BT  recursively  ...easily
int HeightofBT(struct Node* root)
{
   if(root == NULL)
   {
       return 0;
   }

    int heightL = HeightofBT(root->left);
    int heightR = HeightofBT(root->right);
    return max(heightL, heightR) + 1;

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

    /*    1         
        /  \
       2    3         
      / \   / \
     4   5 6   7       ht of this tree = 3

    */

     cout<<HeightofBT(root);  // o/p should be 3
 

   
    return 0;
}
