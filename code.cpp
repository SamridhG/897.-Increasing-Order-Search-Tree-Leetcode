/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *newtree;
    Solution()
    {
        newtree=NULL;
    }
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            if(newtree==NULL)
            {
                newtree=new TreeNode(root->val);
            }
            else
            {
                TreeNode* temp=newtree;
                while(temp->right!=NULL)
                {
                    temp=temp->right;
                }
                temp->right=new TreeNode(root->val);
            }
            inorder(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newtree;
    }
};



/// 2nd Approach 100% faster code




class Solution {
public:
   vector<int>A;
   TreeNode *newtree;
   Solution()
   {
       newtree=NULL;
   }
   void inorder(TreeNode *root)
   {
       if(root!=NULL)
       {
           inorder(root->left);
           A.push_back(root->val);
           inorder(root->right);
       }
   }
   TreeNode* increasingBST(TreeNode* root) {
       inorder(root);
       newtree=new TreeNode(A[0]);
       TreeNode *temp=newtree;
       int i=1;
       while(i<A.size())
       {
           temp->right=new TreeNode(A[i]);
           temp=temp->right;
           i++;
       }
       return newtree;
   }
};
