//deletion in BST,minvalue and maxvalue in BST

#include<bits/stdc++.h>
#include<queue>
using namespace std;

class node
{
  public:
  int data;
  node*left;
  node*right;

  node(int d)
  {
    data=d;
    left=right=NULL;
  }
};

void levelOrderTraversal(node* root)
{
  queue<node*> q;
  q.push(root); 
  q.push(NULL);//separator

  while(!q.empty())
  {
    node*temp=q.front();
    q.pop();

    if(temp == NULL)//last level completely traversed
    {
       cout<<endl;
       if(!q.empty())//q still has some child nodes
       {
          q.push(NULL);
       }
    }
    else 
    {
      cout<<temp->data<<" ";
      if(temp->left)
    {
      q.push(temp->left);
    }

    if(temp->right)
    {
      q.push(temp->right);
    }
    }
  }
}

node* insertBST(node*&root,int data)
{
  if(root == NULL)
  {
    root = new node(data);
    return root;
  }

  if(data > root->data)
  {
    root->right = insertBST(root->right,data);
  }
  else 
  {
    root->left = insertBST(root->left, data);
  }
  return root;
}

void takeInput(node*&root)
{
  int data;
  cin>>data;

  while(data != -1)
  {
    root = insertBST(root,data);
    cin>>data;
  }
}

node* minValue(node*root)
{
  node*temp=root;

  while(temp->left != NULL)
  {
    temp=temp->left;
  }
  return temp;
}

node* maxValue(node*root)
{
  node*temp=root;

  while(temp->right != NULL)
  {
    temp=temp->right;
  }
  return temp;
}

node* deleteBST(node*root,int x)
{
  if(root == NULL)
  {
    return root;
  }

  if(root->data == x)
  {
    //0 child
    if(root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }

    //1 child
    //left child
    if(root->left!=NULL && root->right == NULL)
    {
      node*temp=root->left;
      delete root;
      return temp;
    }
    //right child
    if(root->left == NULL && root->right != NULL)
    {
      node*temp=root->right;
      delete root;
      return temp;
    }

    //2 child
    if(root->left!=NULL && root->right!=NULL)
    {
      int mini = minValue(root->right)->data;
      root->data = mini;
      root->right = deleteBST(root->right,mini);
      return root;
    }

  }
  else if(root->data > x)
  {
    root->left = deleteBST(root->left,x);
    return root;
  }
  else 
  {
    root->right = deleteBST(root->right,x);
    return root;
  }
}

int main()
{
  node*root = NULL;
  cout<<"Enter data to create BST"<<endl;
  takeInput(root);

  root = deleteBST(root,30);

  cout<<"Deleting value & Printing BST"<<endl;
  levelOrderTraversal(root);

  cout<<"Minvalue is : "<<minValue(root)->data<<endl;

  cout<<"Maxvalue is : "<<maxValue(root)->data<<endl;

  return 0;
}

// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(root)
//         {
//             if(key < root->val)
//             {
//                 root->left = deleteNode(root->left,key);
//             }
//             else if(key > root->val)
//             {
//                 root->right = deleteNode(root->right,key);
//             }
//             else 
//             {
//                 if(!root->left && !root->right)//no child
//                 {
//                     return NULL;
//                 }
//                 if(!root->left || !root->right)//1 child
//                 {
//                     return root->left? root->left : root->right;
//                 }
//                 TreeNode* temp = root->left;//2 child
//                 while(temp->right != NULL)
//                 {
//                     temp=temp->right;
//                 }
//                 root->val = temp->val;//minimum value
//                 root->left = deleteNode(root->left,temp->val);
//             }
//         }
//         return root;
//     }
// };