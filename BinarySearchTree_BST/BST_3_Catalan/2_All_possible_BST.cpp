#include<iostream>
#include<vector>
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
        right= NULL;
    }

};

void Preorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root->data <<" ";
    Preorder(root->left);
    Preorder(root->right);
}

// this function will return a vector which contains the root of each valid BST  that can be formed with the number
vector<Node*> BuildBSTs(int start, int end)
{
    vector<Node*> trees ;
    
    if(start>end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start; i<=end; i++)
    {
        vector<Node*> leftSubtrees = BuildBSTs(start , i-1);
        vector<Node*> rightSubtrees = BuildBSTs(i+1, end);

        for(int j=0; j<leftSubtrees.size() ; j++)
        {
            Node* left = leftSubtrees[j];

            for(int k=0; k<rightSubtrees.size(); k++)
            {
                Node* right = rightSubtrees[k];

                Node* node = new Node(i);
                node->left = left;
                node->right = right;

                trees.push_back(node);
            }
        }
    }

    return trees;
}



int main()
{                                       // n=3   c3 = 5     
    vector<Node*> totalTrees   = BuildBSTs(1,3); // here C3 = 5 BST Should be formed
    for(int i=0; i<totalTrees.size() ; i++)
    {
        cout<< (i+1)<<" : ";
        Preorder(totalTrees[i]);   // 5 BST's   preorder sequence will be printed. 
        cout<<endl;
    }
    
    return 0;
}