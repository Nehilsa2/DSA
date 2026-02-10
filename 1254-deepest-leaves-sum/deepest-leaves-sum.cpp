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
    int sum = 0;
    int lastlevel = 0;
    int height(TreeNode*root){
        if(!root) return 0;

        int left  = height(root->left);
        int right = height(root->right);

        return max(left,right) + 1;
    }
    void dfs(TreeNode*node,int level){
        if(!node) return;
        if(level==lastlevel){
            sum+=node->val;
            return;
        }

        dfs(node->left,level+1);
        dfs(node->right,level+1);

    }
    int deepestLeavesSum(TreeNode* root) {
        lastlevel = height(root);

        dfs(root,1);

        return sum;

    }
 
};