class Solution {
public:
    vector<vector<int>> ans;
    vector<int> adj[1000];
    int n;
    void dfs(int node , vector<int> &a){
        if(node == n-1){
            a.push_back(node);
            ans.push_back(a);
            a.pop_back();
            return;
        }
        a.push_back(node);
        for (auto i : adj[node])
            dfs(i, a);
        a.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        for(int i =0; i<n; i++){
            for (auto j : graph[i])
                adj[i].push_back(j);
        }        
        vector<int>a;
        a.push_back(0);
        for (auto i : adj[0]){
            dfs(i, a);
        }
        return ans;
    }
};
