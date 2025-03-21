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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        map<int,int> inmap;
        for(int i =0;i<inorder.size();i++){
            inmap[inorder[i]] = i;
        }
        return buildTree(postorder, 0, postorder.size() -1,inorder,0,inorder.size() -1, inmap);
    }
    TreeNode* buildTree(vector<int>& postorder, int postStart,int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &inmap){
        if(inStart >  inEnd || postStart > postEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inroot = inmap[postorder[postEnd]];
        int nums = inroot - inStart;

        root->left = buildTree(postorder,postStart,postStart + nums - 1, inorder,inStart,inroot -1,inmap);
        root->right = buildTree(postorder,postStart + nums,postEnd -1,inorder,inroot +1 ,inEnd,inmap);

        return root;
    }
};
