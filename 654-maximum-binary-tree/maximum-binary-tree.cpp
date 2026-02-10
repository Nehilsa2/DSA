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
    int n = 0;

    int findmaxindex(vector<int>&nums,int start,int end){
        int maxindex = -1;
        int maxelement = INT_MIN;
        for(int i=start;i<=end;i++){
            if(nums[i]>maxelement){
                maxelement = nums[i];
                maxindex = i;
            }
        }

        return maxindex;
    }
    TreeNode*build(vector<int>&nums,int start,int end){

        if(end<start || start<0 || end>=n) return NULL;

        int ind = findmaxindex(nums,start,end);

        TreeNode*root = new TreeNode(nums[ind]);

        root->left = build(nums,start,ind-1);
        root->right = build(nums,ind+1,end);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        n = nums.size();
        TreeNode*root = build(nums,0,n-1);

        return root;
    }

    //root->left
    //root->right 
};