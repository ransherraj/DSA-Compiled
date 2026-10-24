/*

Undirected Graph Cycle
Solved
Difficulty: MediumAccuracy: 30.13%Submissions: 785K+Points: 4Average Time: 20m
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 

1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 

No cycle in the graph.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V

*/

class Solution {
    
  public:
    bool dfs(vector<vector<int>>& edges, vector<bool>&vis, int edge, int parent){
        vis[edge] = true;
        for(auto newEdge : edges[edge]){
            if(!vis[newEdge]){
                if(dfs(edges, vis, newEdge, edge )){
                    return true;
                }
            }
            else if(newEdge != parent){
                return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool>vis(V, false);
        // Code here
        vector<vector<int>> adj(V);
        for(auto edge : edges){
           int src = edge[0], dst = edge[1];
           adj[src].push_back(dst);
           adj[dst].push_back(src);
        }
        for(int i = 0; i<V; i++){
                if(!vis[i]){
                    if(dfs(adj, vis, i, -1 )) return true;
                }
        }
        return false;
    }
};
