//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    struct Cell
    {
        int cost;
        int x, y;

        // Overload the greater operator for the priority queue to work as a min-heap
        bool operator>(const Cell &other) const
        {
            return cost > other.cost;
        }
    };
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();

        // Define the possible movements: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Priority queue to store the cells to explore (min-heap)
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        // 2D vector to keep track of the minimum cost to reach each cell
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize the starting point
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        // While there are cells to explore
        while (!pq.empty())
        {
            Cell current = pq.top();
            pq.pop();

            int x = current.x;
            int y = current.y;
            int currentCost = current.cost;

            // If we reached the bottom-right corner, return the minimum cost
            if (x == n - 1 && y == n - 1)
            {
                return currentCost;
            }

            // Explore the neighboring cells in 4 directions
            for (const auto &dir : directions)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Check if the neighboring cell is within the grid bounds
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    int newCost = currentCost + grid[nx][ny];

                    // If a cheaper path is found, update the distance and add to the priority queue
                    if (newCost < dist[nx][ny])
                    {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }

        // Return the minimum cost to reach the bottom-right corner (if no valid path, return infinity)
        return dist[n - 1][n - 1];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends