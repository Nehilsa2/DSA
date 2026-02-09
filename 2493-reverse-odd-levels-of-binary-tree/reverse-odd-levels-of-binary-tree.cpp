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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        bool even = true;

        while(!q.empty()){
            int sz = q.size();

            vector<TreeNode*>v;

            for(int i=0;i<sz;i++){
                TreeNode*curr = q.front();
                if(!even){
                    v.push_back(curr);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                q.pop();

            }

            if(!even){
                int i=0;
                int j = sz-1;

                while(i<=j){
                    swap(v[i]->val,v[j]->val);
                    i++;
                    j--;
                }
            }

            even = !even;

        }

        return root;

    }
};