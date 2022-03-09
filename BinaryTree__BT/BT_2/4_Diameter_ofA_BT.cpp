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


int calcHeight(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}



int calcDiameter(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    // case -1 root is  a part of diameter  - ht of binary tree
    int HeightL = calcHeight(root->left);
    int HeightR = calcHeight(root->right);
    int currDiameter = HeightL + HeightR + 1;

    // case 2  - root is not a part of diameter   - find out ...left diameter & right diamter
    int lDiameter = calcDiameter(root->left);
    int RDiameter = calcDiameter(root->right); 

    return max(currDiameter , max(lDiameter , RDiameter));  // max of these three


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

     cout<<calcDiameter(root);
 

   
    return 0;
}
