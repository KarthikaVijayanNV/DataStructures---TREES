#include<iostream>
#include<climits>
#include<stack>
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

//  traversing zigzag and printing here itself

void ZigZagTraversal(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    stack<Node*> currentLevel;
    stack<Node*> nextLevel;

    bool leftToRight = true;

    currentLevel.push(root);

    while(!currentLevel.empty())
    {
        Node* temp = currentLevel.top();
        currentLevel.pop();

        if(temp)
        {
            cout<<temp->data <<" ";

            if(leftToRight)
            {
                if(temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if(temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            // else means RightToleft
            else
            {
                if(temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if(temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }
        // current level is empty means One level is completed
        if(currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel , nextLevel);  // swap is inbuilt function
        }

    }

}




int main()
{
    /* 
        BST 
   
          12
         /  \
        9    15
       / \  
      5   10
       
        Zigzag Traversal = 12,15,9,5,10 
                     
    */

   struct Node* root = new Node(12);
   root->left = new Node(9);
   root->right = new Node(15);
   root->left->left = new Node(5);
   root->left->right = new Node(10);

   // test
   ZigZagTraversal(root);   // o/p is   12,15,9,5,10 
    
    
    return 0;
}