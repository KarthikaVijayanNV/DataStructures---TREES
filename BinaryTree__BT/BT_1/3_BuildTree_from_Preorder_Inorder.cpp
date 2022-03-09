#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left ;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


int Search(int Inorder[], int start, int end, int curr) // linear search method
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


Node* buildTree(int Preorder[], int Inorder[], int start, int end)
{
    static int idx = 0;
    if(start > end)  //base condition
    {
        return NULL;
    }

    int curr = Preorder[idx];
    idx++;

    Node* node = new Node(curr);
    if(start == end)  // side case
    {
        return node;
    }
    int pos = Search(Inorder, start, end, curr);
    node->left = buildTree(Preorder, Inorder, start, pos-1);
    node->right = buildTree(Preorder, Inorder , pos+1, end);

    return node;
}

// cheking whether the tree is built in the right way or not???
void InorderPrint(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InorderPrint(root->left);
    cout<<root->data<<" ";
    InorderPrint(root->right);
}



int main()
{   
    int Preorder[] = {1,2,4,3,5};
    int Inorder[] = {4,2,1,5,3};

    // get the node here....
    Node* root = buildTree(Preorder, Inorder, 0, 4);

    //print and check
    InorderPrint(root);   //   {4,2,1,5,3}     o/p should be like this

    return 0;
}


