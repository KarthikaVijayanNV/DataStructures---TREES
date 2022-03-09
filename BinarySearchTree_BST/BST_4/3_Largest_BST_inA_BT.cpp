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
        right = NULL;
    }
};

// another structure for storing Info: about each node

struct Info
{
    int size;
    int max;
    int min;
    int ans;  // size of largest BST
    bool isBST;
};



Info largestBSTinBT (Node* root)
{
    if(root == NULL)
    {
        return {0, INT_MIN , INT_MAX , 0 , true };
    }
    // leaf node
    if(root->left == NULL && root->right == NULL)
    {
        return {1, root->data , root->data , 1 , true};
    }

    // code for nodes having leftchilds and right childs

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1+ leftInfo.size + rightInfo.size);

    // check if it's forms a BST or not
    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data  && rightInfo.min > root->data)
    {
        curr.max = max(leftInfo.max  , max(root->data , rightInfo.max));
        curr.min = min(leftInfo.min , min (root->data , rightInfo.min));

        curr.ans = curr.size;
        curr.isBST = true;
        
        return curr;
    }
    
    // if it doesn't form a BST
    curr.ans = max (leftInfo.ans , rightInfo.ans);
    curr.isBST = false;
    
    return curr;

}


int main()
{
    /*
       BT 

         15
        / \
       20  30 
      /               BST is there inside this BT   15 -> 30  is a BST      size(2);
      5                                             20->5  is also a BST    size(2);

                                                o/p is 2;
    */

  struct Node* root = new Node(15);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(5);


    /*
         BT  (by default it is a BST)

          5
         / \
        3   6
       / \
      2   4

               size of largest BST = BT itself is a BST 
                 so size =  5
                 o/p should be  5

    */

   struct Node* root1 = new Node(5);
   root1->left = new Node(3);
   root1->right = new Node(6);
   root1->left->left = new Node(2);
   root1->left->right = new Node(4);




  //test
  cout<<"Largest BST in BT : "<<largestBSTinBT(root1).ans<<endl;  // for root1 o/p is 5

    return 0;
}