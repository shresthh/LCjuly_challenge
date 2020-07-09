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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int width = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            int count = q.size();
            int left_idx = q.front().second;
            int right_idx = q.back().second;
            width = max(width, right_idx - left_idx + 1);
            while(count--){
                pair<TreeNode*, int> p = q.front();
                int idx = p.second - left_idx; //so that signed integer does not overflow.
                q.pop();
                if(p.first->left)  q.push({p.first->left, 2*idx+1});
                if(p.first->right) q.push({p.first->right, 2*idx+2});
            }
        }
        return width;
        
    }
};
