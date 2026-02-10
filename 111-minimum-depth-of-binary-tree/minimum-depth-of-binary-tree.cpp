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
    int minDepth(TreeNode* root) {
        
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            TreeNode*node = top.first;
            int level = top.second;

            if(node->left==NULL && node->right==NULL) return level;

            if(node->left) q.push({node->left,level+1});
            if(node->right) q.push({node->right,level+1});
        }

        return 0;
    }
};