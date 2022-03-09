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


void RightView(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i=0; i<n; i++)  // this loop is for the current level
        {
            Node* node = q.front();
            q.pop();

            if(i == n-1) // reached the last element in the level...that is right viewable element
            {
                cout<<node->data<<" ";
            }
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }

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

       right view = 1,3,7                                
    */ 
     
   RightView(root);   // 1,3,7
   

   
    return 0;
}
