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

// recursively counting nodes..easily
int CountNodes(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return CountNodes(root->left) + CountNodes(root->right) + 1;
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
     4   5 6   7       total no:of nodes = 7 nodes

    */

   cout<<CountNodes(root); // 0/p should be    7 

   
    return 0;
}
