#include<iostream>
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

// IsIdentical or not
bool IsIdentical(Node* root1 , Node* root2)
{
    if( root1 == NULL && root2 == NULL)
    {
        return true;
    }

    else if(root1 == NULL || root2 == NULL)   // either of one is null
    {
        return false;
    }

    else  // both root is having values
    {
        bool Cond1 = root1->data == root2->data;
        bool Cond2 = IsIdentical(root1->left , root2->left);
        bool Cond3 = IsIdentical(root1->right , root2->right);

        if(Cond1 && Cond2 && Cond3 )    // 3 of this conditon is true then it is true
        {
            return true; 
        }
        //if not
        return false;
    }
}


int main()
{
    /*
       BST 1

        2
       / \
      1   3

    */

    struct Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    /*
        BST 2

        2
       / \
      1   5

    */
    struct Node* root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(5);

    //test
    if(IsIdentical(root1 , root2))   //change the values and check
    {
        cout<< " BSTs are Identical"<<endl;
    }
    else
    {
        cout<<" BSTs not Identical"<<endl;
    }

    return 0;
}