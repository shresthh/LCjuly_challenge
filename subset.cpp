class Solution {
    void rec(vector<int> &nums, vector<vector<int>> &ans, vector<int>temp, int idx){
        ans.push_back(temp);
        for(int i = idx; i<nums.size(); i++){
            temp.push_back(nums[i]);
            rec(nums, ans, temp, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        rec(nums, ans,temp, 0);
        return ans;
        
    }
};
