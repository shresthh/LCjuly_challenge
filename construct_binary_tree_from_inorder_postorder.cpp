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
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int start, int end, int &j){
        int index;
        if(start>end)
            return NULL;

        for(int i = start; i<=end; i++){
            if(inorder[i] == postorder[j]){
                index = i;
                break;
            }
        }
        TreeNode *root = new TreeNode(inorder[index]);

        j--;
        root->right = solve(inorder, postorder, index+1, end, j);
        root->left = solve(inorder, postorder, start, index-1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int j = postorder.size()-1;
        return solve(inorder, postorder, 0, inorder.size()-1, j);
        
    }
};
