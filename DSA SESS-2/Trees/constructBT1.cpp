//construct tree from inorder and preorder

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

class Solution {
public:

    //I commented this code because it causing extra O(N) T.C on every recursive call in solver function to find position it element in inorder so I used unorderd_map to store element with its index to retrive the position in O(1).
    
    // int findPosition(vector<int>& in, int element, int n)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         if(in[i] == element)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    TreeNode* Solve(vector<int>& in, vector<int>& pre,int &index,int inorderStart, int inorderEnd, int n,unordered_map<int,int>&m)
    {
        if(index >=n || inorderStart > inorderEnd)
        {
            return NULL;
        }
        int element = pre[index++];
        int position = m[element];
        TreeNode* root = new TreeNode(element);
        // int position = findPosition(in,element,n);

        root->left = Solve(in,pre,index,inorderStart,position-1,n,m);
        root->right = Solve(in,pre,index,position+1,inorderEnd,n,m);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int size = inorder.size();
        int inorderStart = 0;
        int inorderEnd = size-1;
        unordered_map<int,int> m;
        for(int i=0;i<size;i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode* ans = Solve(inorder,preorder,preOrderIndex,inorderStart,inorderEnd,size,m);
        return ans;
    }
};