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


void LeftView(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        for(int i=0; i<n; i++)  // for current level
        {
            Node* node = q.front();
            q.pop();

            if(i == 0)    // 1st node at each level is printing ....that is leftview
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
    struct Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
   

    /*    5                                 
        /  \                        
       3     6                           
      / \                  
     2   4                

       right view = 5,3,2                              
    */ 
     
   LeftView(root);  // 5,3,2
   

   
    return 0;
}
