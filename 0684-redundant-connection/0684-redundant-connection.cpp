class Solution {
public:

    bool dfs(vector<vector<int>> &adj,int parent, vector<int> &visited, int node){
        visited[node] = 1;
        for(auto adjnode : adj[node]){
            if(!visited[adjnode]){
                if(dfs(adj,node,visited,adjnode)){
                    return true;
                }
            }
            else if(adjnode != parent){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();
        vector<vector<int>> adj(n+1);
        

        for(int i=0; i<n; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);

            vector<int> visited (n+1,0);
            if(!visited[i]){
                if(dfs(adj,-1,visited,edges[i][0])){
                    return {edges[i][0],edges[i][1]};
                }
            }
        }
        return {};
    }
};