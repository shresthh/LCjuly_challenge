class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<string, int> m;
        for(int i = 0; i< N; i++){
            string s(cells.begin(), cells.end());
            if(m.find(s) != m.end()){
                int loop_length = i - m[s];
                int new_N = (N-i)% loop_length;
                return prisonAfterNDays(cells, new_N);
            }
            else{
                m.insert({s,i});
                int prev = cells[0];
                for (int j = 1; j<7;j++){
                    int next = cells[j+1];
                    int curr = cells[j];
                    cells[j] = prev==next;
                    prev = curr;
                }
            }
            cells[0] = 0;
            cells[7] = 0;
        }
        return cells;

    }
};
