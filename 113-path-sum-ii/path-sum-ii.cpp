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
     vector<vector<int>>ans;
     void solve(TreeNode*root,int target,vector<int>temp){
        if(!root) return ;

        int newtarget = target - root->val;

        temp.push_back(root->val);

        if(newtarget==0 && !root->left && !root->right){
            ans.push_back(temp);
            return;
        } 
        

        solve(root->left,newtarget,temp);
        solve(root->right,newtarget,temp);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,targetSum,temp);

        return ans;
    }
};