#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right= NULL;
    }
};

int Search(int Inorder[], int start, int end , int curr) // Linear search method
{
    for(int i=start; i<=end; i++)
    {
        if(Inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int Postorder[], int Inorder[], int start , int end)
{
    static int idx = 4;
    if(start > end)  // base condition
    {
        return NULL;
    }

    int curr = Postorder[idx];
    idx--;

    Node* node = new Node(curr);
    if(start == end)  // side case
    {
        return node;
    }
    int pos = Search(Inorder , start, end , curr);
    node->right = buildTree(Postorder ,Inorder , pos+1, end);
    node->left = buildTree(Postorder ,Inorder ,start ,pos-1);

    return node;
}

// checking whether the tree is built in the right way or not???
void InorderPrint( Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}




int main()
{   
    int Postorder[] = {4,2,5,3,1};
    int Inorder[]= {4,2,1,5,3};

    //built tree call..getting the node
    Node* root = buildTree(Postorder , Inorder, 0,4);  // tree is built

    //check with Inorder print
    InorderPrint(root);        // o/p should be {4,2,1,5,3}





    return 0;
}