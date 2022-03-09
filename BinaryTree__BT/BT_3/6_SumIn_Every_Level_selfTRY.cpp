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


void SumINAllLevels(struct Node* root)
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
        int sum =0;
        for(int i=0; i<n; i++)  // for current level
        {
            Node* node = q.front();
            q.pop();

            sum+= node->data;  // finding some in each level

            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }  
        cout<<sum<<endl;   // befor going to next level giving output
    }
}




int main()
{
    struct Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(6);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
   

    /*    5                                 
        /  \                        
       3     6                           
      / \                  
     2   4                

       sum in all levels = 5  (oth level)
                           9 (6+3  1st level)
                           6  (4+2  2nd level)
                o/p should be like this                             
    */ 
     
    struct Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
   

    /*    1                                 
        /  \                        
       2    3                            
      / \   / \                 
     4   5 6   7                

       sum in all levels  = 1   (1)
                            5    (2+3)
                            22   (4+5+6+7)
                                                         
    */ 


    SumINAllLevels(root2);  // change root1 and root2 and check the ans
     
   
    return 0;
}
