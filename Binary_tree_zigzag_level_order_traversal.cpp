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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        TreeNode *curr = root;
        stack1.push(curr);
        while(!stack1.empty() || !stack2.empty()){
            vector<int> temp;
            while(!stack1.empty()){
                curr = stack1.top();
                
                temp.push_back(curr->val);
                if(curr->left) stack2.push(curr->left);
                if(curr->right) stack2.push(curr->right);
                stack1.pop();  
            }
            if(!temp.empty())
                ans.push_back(temp);
            temp.clear();
            while(!stack2.empty()){
                curr = stack2.top();
                temp.push_back(curr->val);
                if(curr->right) stack1.push(curr->right);
                if(curr->left) stack1.push(curr->left);
                stack2.pop();
            }
            if(!temp.empty())
                ans.push_back(temp);
            temp.clear();

        }
        
        return ans;
    }
};
