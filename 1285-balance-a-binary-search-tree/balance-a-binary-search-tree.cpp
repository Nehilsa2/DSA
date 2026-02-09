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
    vector<int>temp;
    void inorder(TreeNode*node){

        if(!node) return;

        inorder(node->left);
        temp.push_back(node->val);
        inorder(node->right);
    }
    TreeNode*build(int l,int r){
        if(l>r){
            return NULL;
        }

        int mid = (l+r)/2;
        TreeNode*root = new TreeNode(temp[mid]);

        root->left = build(l,mid-1);
        root->right = build(mid+1,r);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        inorder(root);
        return build(0,temp.size()-1);  
    }

    //[1,2,3,4]
};