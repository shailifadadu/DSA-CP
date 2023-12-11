//create binary tree from inorder and postorder

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
  public:
  int data;
  TreeNode*left;
  TreeNode* right;

  TreeNode(int d)
  {
    data=d;
    left=right=NULL;
  }
};

class Solution {
public:

    // void createMapping(vector<int>& in, map<int, int>& nodeToIndex) {
    //     int n = in.size();
    //     for (int i = 0; i < n; i++) {
    //         nodeToIndex[in[i]] = i;
    //     }
    // }

    TreeNode* Solve(vector<int>& in, vector<int>& post, int& postindex, int inorderStart, int inorderEnd, map<int, int>& nodeToIndex) {
        if (postindex < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = post[postindex--];
        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root->right = Solve(in, post, postindex, position + 1, inorderEnd, nodeToIndex);
        root->left = Solve(in, post, postindex, inorderStart, position - 1, nodeToIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postOrderIndex = n - 1;
        map<int, int> nodeToIndex;

        for(int i=0;i<n;i++)
        {
            nodeToIndex[inorder[i]]=i;
        }
       // createMapping(inorder, nodeToIndex);
        TreeNode* ans = Solve(inorder, postorder, postOrderIndex, 0, n - 1, nodeToIndex);
        return ans;
    }
};