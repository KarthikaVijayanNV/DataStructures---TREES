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


// finding diameter more optimised approach
int calcDiameter(struct Node* root , int* height)
{
    if(root == NULL)
    {   
        *height = 0;
        return 0;
    }

    int lheight = 0 , rheight =0;

    int lDiameter = calcDiameter(root->left , &lheight);
    int rDiameter = calcDiameter(root->right , &rheight);

    int currHeight = lheight + rheight +1;
    *height = max(lheight , rheight) + 1;

    return max(currHeight, max(lDiameter , rDiameter));

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
     4   5 6   7       diameter of this tree = 5

    */
     int height =0;
     cout<<calcDiameter(root,&height);
 

   
    return 0;
}
