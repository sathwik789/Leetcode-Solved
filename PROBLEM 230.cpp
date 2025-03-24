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
    void inorder(TreeNode* root,int k, int &cnt,int &ksmallest){
        if(!root || cnt >= k){
            return;
        }
        inorder(root->left,k,cnt,ksmallest);
        cnt++;
        if(cnt == k){
            ksmallest = root->val;
            return;
        }
        inorder(root->right,k,cnt,ksmallest);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return 0;
        }
        int ksmallest = 0;
        int cnt = 0;
        inorder(root,k,cnt,ksmallest);
        return ksmallest;
    }
};
