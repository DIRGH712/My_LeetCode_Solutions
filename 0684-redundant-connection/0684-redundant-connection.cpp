/*
    Given undirected graph, return an edge that can be removed to make a tree
    Ex. edges = [[1,2],[1,3],[2,3]] -> [2,3]

    If n nodes & n edges, guaranteed a cycle
    How to know creating cycle? When connecting a node already connected
    Union Find: can find this redundant edge, track parents & size

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        vector<int> parents;
        vector<int> size;
        for (int i = 0; i < n + 1; i++) {
            parents.push_back(i);
            size.push_back(1);
            
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            if (!doUnion(parents, size, n1, n2)) {
                result = {n1, n2};
                break;
            }
        }
        return result;
    }
private:
    int doFind(vector<int>& parent, int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = doFind(parent, parent[node]); 
    }
    
    bool doUnion(vector<int>& parents, vector<int>& size, int n1, int n2) {
        int p1 = doFind(parents, n1);
        int p2 = doFind(parents, n2);
        if (p1 == p2) {
            return false;
        }
        
        if (size[p1] > size[p2]) {
            parents[p2] = p1;
            size[p1] += size[p2];
        } else {
            parents[p1] = p2;
            size[p2] += size[p1];
        }
        
        return true;
    }
};
