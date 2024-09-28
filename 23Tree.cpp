#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
        TreeNode *left;
        TreeNode* right;
        TreeNode* middle;
        int sval;
        int lval;
        TreeNode(int val) 
        {
            sval=val;
            lval=-1;
            left=right=middle=NULL;
        }
};

TreeNode* insertTwoThree(TreeNode* root,int key,int& pathway)
{
    
if(root==NULL){
    pathway=1;
    return root=new TreeNode(key);
} 

if((root->left==NULL && root->middle==NULL && root->right==NULL))
{
    if(root->sval==-1 && root->lval!=-1)
    {
        if(root->lval > key)
        {
            root->sval=key;
        }
            
        else
        {
            root->sval=root->lval;
            root->lval=key;
        }
        
    }
    else if(root->sval!=-1 && root->lval==-1)
    {
     if(root->sval > key)
     {
         root->lval=root->sval;
         root->sval=key;
     }
     else root->lval=key;
    }
    else if(root->sval!=-1 && root->lval!=-1)
    { // both elements present
     int middle;
     int lower;
     int higher;
     pathway=1;
     if((root->sval > root->lval && root->sval < key)) 
     {
         lower=root->lval;
         middle=root->sval;
         higher=key;
     }
     else if(root->sval < root->lval && root->sval > key)
     {
        lower=key;
        middle=root->sval;
        higher=root->lval;
     }
     
     else if(root->lval > root->sval && root->lval < key) 
     {
         lower=root->sval;
         middle=root->lval;
         higher=key;
         //cout<<"here";
     }
     else if(root->lval < root->sval && root->lval > key)
     {
        lower=key;
        middle=root->lval;
        higher=root->sval;
     }
     
     else {
         middle=key;
         if(root->sval>root->lval){lower=root->lval;higher=root->sval;}
         else {
             lower=root->sval;higher=root->lval;
         }
     }
     TreeNode* newNode=new TreeNode(middle);
     newNode->left=new TreeNode(lower);
     //cout<<"higher is"<<higher<<endl;
     newNode->right=new TreeNode(higher);
     pathway=1;
     return newNode;
    }
    
} // leaf node ends
else
{
 if(root->sval > key)
 {
     TreeNode* node=insertTwoThree(root->left,key,pathway);
     if((root->sval!=-1 || root->lval!=-1) && pathway)
     {
         
         root->left=node->left;
         root->middle=node->right;
         if(root->sval==-1){root->sval=node->sval;}
         else{
             root->lval=root->sval;
             root->sval=node->sval;
         }
         delete node;
         
     }
     else
     {
         root->left=node;
     }
 }
 else if(root->lval < key)
 {
     TreeNode* node=insertTwoThree(root->right,key,pathway);
     if((root->sval!=-1 || root->lval!=-1) && pathway)
     {
         
        root->middle=node->left;
        root->right=node->right;
         if(root->lval==-1){root->lval=node->sval;}
         else{
             root->sval=root->lval;
             root->lval=node->sval;
         }
        delete node;
     }
     else
     {
         root->right=node;
     }
 }
 else{
     TreeNode* node=insertTwoThree(root->middle,key,pathway);
     root->middle=node;
 }
 
}
return root;
}

void LOT(TreeNode* root)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty())
    {
        
        TreeNode* front=q.front();
        if(front->left!=NULL)q.push(front->left);
        if(front->middle!=NULL)q.push(front->middle);
        if(front->right!=NULL)q.push(front->right);
        cout<<"("<<front->sval<<","<<front->lval<<")\t";
        q.pop();
    }
}
int main()
{
    TreeNode* root=NULL;
    cout<<"Enter number of elements"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        int pathway=0;
        root=insertTwoThree(root,k,pathway);
        LOT(root);
        cout<<endl<<endl<<endl;
        //cout<<"Printing sval of root of tree "<<root->sval<<endl;
    }
    cout<<"Printing LOT"<<endl;
    LOT(root);
    return 0;
}


