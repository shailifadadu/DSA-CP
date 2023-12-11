//diameter of tree
//the longest path between any 2 nodes
//left,right,combo of left and right

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
  public:
  int data;
  TreeNode*left;
  TreeNode*right;

  TreeNode(int d)
  {
    data=d;
    left=right=NULL;
  }
};

class Solution
{
  public:

  int height(TreeNode* root)
  {
    if(root == NULL)
    {
      return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;
    return ans;
  }

  int diameter(TreeNode* root)
  {
    if(root == NULL)
    {
      return 0;
    }
    int left = diameter(root->left);
    int right = diameter(root->right);
    int both = height(root->left) + 1 + height(root->right);

    int ans = max(max(left,right),both);
    return ans;
  }
};