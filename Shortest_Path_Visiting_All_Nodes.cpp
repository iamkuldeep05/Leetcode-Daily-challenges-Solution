/*
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
Example 1:
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]
Example 2:
Input: graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
Output: 4
Explanation: One possible path is [0,1,4,2,3]
*/

/*# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We want to find the shortest path that visits every node in an undirected, connected graph.
# Approach
<!-- Describe your approach to solving the problem. -->
We use a bitmask to represent visited nodes and a queue for a breadth-first search (BFS) approach.
Initialize the queue with all nodes as starting points and mark them as visited.
Perform BFS, exploring neighboring nodes and updating the bitmask to mark visited nodes.
Return the number of steps when all nodes are visited.

# Complexity
- Time complexity: - O(2^n * n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(2^n * n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```*/
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all = (1 << n) - 1;
        
        // Use a vector of vectors to mark visited nodes
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        queue<pair<int, int>> q;
        
        // Initialize the queue with all nodes as starting points
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        
        int steps = 0;
        
        while (!q.empty()) {
            int qSize = q.size();
            
            for (int i = 0; i < qSize; i++) {
                auto [node, mask] = q.front();
                q.pop();
                
                if (mask == all) {
                    return steps;
                }
                
                for (int neighbor : graph[node]) {
                    int newMask = mask | (1 << neighbor);
                    
                    if (!visited[neighbor][newMask]) {
                        visited[neighbor][newMask] = true;
                        q.push({neighbor, newMask});
                    }
                }
            }
            
            steps++;
        }
        
        return -1; // No valid path found
    }
};



```