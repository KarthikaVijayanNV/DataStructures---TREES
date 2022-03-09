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

int calHeight(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return max(calHeight(root->left) , calHeight(root->right)) +1;
}


bool isBalanced(struct Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    if(isBalanced(root->left) == false)
    {
        return false;
    }
    if(isBalanced(root->right) == false)
    {
        return false;
    }

    int Lht = calHeight(root->left);
    int Rht = calHeight(root->right);

    if(abs(Lht - Rht) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}




int main()
{
    struct Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    /*    1                                 
        /  \                        
       2    3                            
      / \   / \                 
     4   5 6   7                

       Balanced height tree                                 
    */ 
     
    struct Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    /*     1                                 
          /                          
         2                               
        /                   
       3                  

      UnBalanced height tree                                 
    */ 

   if(isBalanced(root2))    // check by changing   root1   and    root2
   {
       cout<<"Balanced height tree"<<endl;
   }
   else
   {
       cout<<"Not Balanced height tree"<<endl;
   }
   

   
    return 0;
}
