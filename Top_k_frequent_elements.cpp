class Solution {
        
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> result;
        for(auto a : nums)
            mp[a]++;
        
        // map ka first - original number and map.second is frequency of the number.
        //queue ka first is freq and second is original number.
        priority_queue<pair<int, int>> pq;
        for (auto a : mp){
            pq.push({a.second, a.first});
            if(pq.size()>mp.size() - k){
                result.emplace_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
        
    }
};
