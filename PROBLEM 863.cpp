/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lev = q.size();
            for(int i =0;i<lev;i++){
                TreeNode* node= q.front();
                q.pop();
                if(node->left){
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> parent;
        markparent(root,parent,target);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> qq;
        qq.push(target);
        visited[target]  = true;
        int curr_lev =0;
        while(!qq.empty()){
            int size = qq.size();
            if(curr_lev++ == k) break;
            for(int i =0;i<size;i++){
                TreeNode* node = qq.front();
                qq.pop();
                if(node->left && !visited[node->left]){
                    qq.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    qq.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    qq.push(parent[node]);
                    visited[parent[node]]  = true;
                }
            }
        }
        while(!qq.empty()){
            ans.push_back(qq.front()->val);
            qq.pop();
        }
        return ans;
    }
};
