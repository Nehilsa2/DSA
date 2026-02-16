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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>v;
        if(!root) return v;

        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;

            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop();

                temp.push_back(top->val);

                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }

            v.push_back(temp);
        }

        return v;
    }
};