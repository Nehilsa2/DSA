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
    string temp = "";
    vector<string> v;

    int todecimal(string s){
        int num = 0;
        for(char c : s){
            num = (num<<1) + (c-'0');
        }
        return num;
    }

    void solve(TreeNode* root){
        if(!root) return;

        temp.push_back(root->val + '0');

        if(!root->left && !root->right){
            v.push_back(temp);
        }

        solve(root->left);
        solve(root->right);

        temp.pop_back();
    }

    int sumRootToLeaf(TreeNode* root) {

        solve(root);  

        int sum = 0;
        for(auto &i : v){
            sum += todecimal(i);
        }

        return sum;
    }
};