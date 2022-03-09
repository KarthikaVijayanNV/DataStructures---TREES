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



void Flatten(struct Node* root)
{
    if(root == NULL   ||  (root->left == NULL && root->right == NULL) )
    {
        return;
    }

    if(root->left != NULL)
    {
        Flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL)
        {
            t= t->right;
        }
        t->right = temp;
        
    }
    
    Flatten(root->right);
}

//after flattening print the inorder series of flattened BT  and check whether it's right or not

void PrintInorder(struct Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    PrintInorder(root->left);
    cout<<root->data<<" ";
    PrintInorder(root->right);
}




int main()
{
    struct Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
   
    root->right->right = new Node(6);

    /*    4                   after flattening      4
        /  \                                         \
       9     5                                        9
      / \     \                                        \
     1   3     6                                        1
    before flattening Inorder = 1,9,3,4,5,6              \
                                                          3
                                                           \
                                                            5
                                                             \
                                                              6

                                after flattening inorder = 4,9,1,3,5,6
    */




    //before flattening
     PrintInorder(root);  // 1,9,3,4,5,6   

     Flatten(root);    cout<<endl;   // flattening done  

     PrintInorder(root);//  4,9,1,3,5,6

    return 0;
   

}
