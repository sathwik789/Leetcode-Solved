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
    bool isValidBST(TreeNode* root) {
        return validBST(root,LONG_MIN,LONG_MAX);
    }
    bool validBST(TreeNode* root,long longMin,long longMax){
        if(!root) return true;
        if(root->val  >= longMax || root->val <= longMin) return false;
        return validBST(root->left,longMin, root->val) 
            && validBST(root->right,root->val,longMax);
    }
};
