/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20

Intuition
The intuition behind the logic of the code is to find the minimum cost to connect all points in a 2D plane using a minimum spanning tree (MST) algorithm. In this case, we are using Prim's algorithm to achieve this. The goal is to create a connected graph such that there is exactly one simple path between any two points, and the total edge cost is minimized.

Approach
Initialization:
We start by initializing several data structures:

n: The number of points.
visited: A boolean array to keep track of whether a point has been added to the MST.
minDist: An array to store the minimum distance from the current MST to each point. Initialize all distances to infinity, except the distance to the first point (which is set to 0).
minCost: A variable to keep track of the total minimum cost, initially set to 0.
Main Loop: We enter a loop that iterates n times, where n is the number of points. In each iteration, we do the following:

Find the vertex u with the smallest minDist[u] among the points that have not been added to the MST yet. This is the core of Prim's algorithm and ensures that we select the point closest to the current MST.

Mark u as visited.

Add minDist[u] to minCost, as this distance becomes part of the MST.

Update Distances: After selecting the vertex u, we update the distances of its neighboring points that have not been added to the MST yet. For each neighboring point v, we calculate the distance from u to v (Manhattan distance) and update minDist[v] if this distance is smaller than the current minDist[v].

Repeat: We repeat the above steps until we have included all n points in the MST.

Return Result: The final value of minCost represents the minimum cost to connect all points in the MST.

Complexity
Time complexity: O(n^2)
Space complexity: O(n)
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
        int minCost = 0;
        
        // Start with the first point
        minDist[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }
            
            visited[u] = true;
            minCost += minDist[u];
            
            // Update minDist for neighboring points
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int distance = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], distance);
                }
            }
        }
        
        return minCost;
    }
};
