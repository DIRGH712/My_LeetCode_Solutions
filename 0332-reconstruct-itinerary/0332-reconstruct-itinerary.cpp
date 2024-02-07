class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (int i = 0; i < tickets.size(); i++) {
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        
        vector<string> result;
        dfs(m, "JFK", result);
        reverse(result.begin(), result.end()); 
        // we are doing something like a toposort, find a node which cannot go any further first and then reverse so it comes last
        return result;
    }
    
    void dfs(unordered_map<string, multiset<string>>& m, string curr, vector<string>& result){
        
        while(!m[curr].empty()){
            string dst = *m[curr].begin();
            m[curr].erase(m[curr].begin());
            dfs(m,dst,result);
        }
        
        result.push_back(curr);
    }
    
};