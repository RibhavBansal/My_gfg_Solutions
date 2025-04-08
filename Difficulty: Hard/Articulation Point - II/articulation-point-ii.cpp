//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& vis, vector<int>& tin, vector<int>& low, int& timer, vector<bool>& isArticulation) {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!vis[v]) {
                dfs(v, u, adj, vis, tin, low, timer, isArticulation);
                low[u] = min(low[u], low[v]);

                // Check articulation condition
                if (low[v] >= tin[u] && parent != -1) {
                    isArticulation[u] = true;
                }

                children++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        // Special case for root
        if (parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> tin(V, -1), low(V, -1), vis(V, 0);
        vector<bool> isArticulation(V, false);
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, adj, vis, tin, low, timer, isArticulation);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) {
                result.push_back(i);
            }
        }

        if (result.empty()) return {-1};
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends