#include<iostream>
#include<climits>
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

int MaxPathSumUtil(Node* root, int &ans)
{
    if(root == NULL)
    {
        return 0;
    }

    int left = MaxPathSumUtil(root->left , ans);
    int right = MaxPathSumUtil(root->right , ans);

    int nodeMax = max(max (root->data , root->data + left + right ),
                    max(root->data +left , root->data +right));

    ans = max(ans ,nodeMax);

    int SinglePathSum = max(root->data , max(root->data+left , root->data +right));
    return SinglePathSum;


}


int MaxPathSum(Node* root)
{
    int ans = INT_MIN;
    MaxPathSumUtil(root, ans); //calling function
    return ans;

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
                    //max path sum is .... 7->3->1->2->5  = 18 is the max pathsum
    */
   cout<<MaxPathSum(root); //  18
    
  

}
