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


int findDist(struct Node* root , int k , int dist)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->data == k)
    {
        return dist;   // whatever the value at dist that time..return that value
    }

    int left = findDist(root->left , k , dist+1);  // n2 (k) is found in the left subtree
    if(left != -1)
    {
        return left;     
    }

    return findDist(root->right , k ,dist+1);   // otherwise ...check right subtree
}



Node* LCA(struct Node* root , int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node* left = LCA(root->left , n1, n2);   // checking the left subtree  ...to find n1 and n2 
    Node* right = LCA(root->right , n1, n2);// checking the right subtree  ...to find n1 and n2 

    if(left != NULL && right != NULL)   // which means n1 and n2 is found in left or right 
    {
        return root;
    }
    if(left == NULL && right == NULL)
    {
        return NULL;
    }

    if(left != NULL)  // right become NULL
    {
        return LCA(root->left , n1, n2);
    }

    return LCA(root->right , n1, n2);   // when left become NULL
}

int DistBTWnodes(struct Node* root , int n1, int n2)
{
    Node* lca =  LCA(root, n1, n2);  // this function will return LCA and store in the node

    int d1 = findDist(lca , n1 ,0) ;
    int d2 = findDist(lca , n2 ,0);

    return d1+d2;
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
     4   5 6   7               

    */


   cout<<DistBTWnodes(root , 4, 7);  // o/p  is 4;  change the nodes and check the values also
 

    return 0;
   

}
