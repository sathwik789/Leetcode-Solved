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
    void cnt(TreeNode* root,int &res){
        if(!root){
            return;
        }
        if(root->left){
            res++;
            cnt(root->left,res);
        }
        if(root->right){
            res++;
            cnt(root->right,res);
        }
    }
    int countNodes(TreeNode* root) {
        // int res =0;
        // if(!root){
        //     return res;
        // }
        // unordered_map<TreeNode*,bool> visited;
        // queue<TreeNode*> q;
        // q.push(root);
        // visited[root] = true;
        // while(!q.empty()){
        //     int size = q.size();
        //     for(int i =0;i<size;i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(node ->left && !visited[node->left]){
        //             visited[node->left] = true;
        //             q.push(node ->left);
        //         }
        //         if(node ->right && !visited[node->right]){
        //             visited[node->right] = true;
        //             q.push(node->right);
        //         }
        //     }
        // }
        // res = visited.size();
        // return res;
        int res = 0;
        if(!root) return res;
        cnt(root,res);
        return res + 1 ;

    }

};/**
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
    void cnt(TreeNode* root,int &res){
        if(!root){
            return;
        }
        if(root->left){
            res++;
            cnt(root->left,res);
        }
        if(root->right){
            res++;
            cnt(root->right,res);
        }
    }
    int countNodes(TreeNode* root) {
        // int res =0;
        // if(!root){
        //     return res;
        // }
        // unordered_map<TreeNode*,bool> visited;
        // queue<TreeNode*> q;
        // q.push(root);
        // visited[root] = true;
        // while(!q.empty()){
        //     int size = q.size();
        //     for(int i =0;i<size;i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(node ->left && !visited[node->left]){
        //             visited[node->left] = true;
        //             q.push(node ->left);
        //         }
        //         if(node ->right && !visited[node->right]){
        //             visited[node->right] = true;
        //             q.push(node->right);
        //         }
        //     }
        // }
        // res = visited.size();
        // return res;
        int res = 0;
        if(!root) return res;
        cnt(root,res);
        return res + 1 ;

    }

};
