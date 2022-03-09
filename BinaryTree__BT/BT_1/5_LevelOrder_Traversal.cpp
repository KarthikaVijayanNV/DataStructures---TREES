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


void printLevelorder(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    // Using a queue for level order traversal
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(node!= NULL)   // if the number taken is not NULL
        {
            cout<<node->data<<" ";
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        else if(!q.empty())  // if the number taken is NULL then check the queue again....whether queue become empty or not
        {
            q.push(NULL);
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

    */

   printLevelorder(root);  // o/p should be   1,2,3,4,5,6,7


    return 0;
}