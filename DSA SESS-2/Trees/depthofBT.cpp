//find height/depth of binary tree
//height is the longest path between root and leaf node

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
};