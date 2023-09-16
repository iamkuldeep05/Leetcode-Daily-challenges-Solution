/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

*/

/*# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The intuition behind this code is to explore the grid while keeping track of the minimum effort required to reach each cell. You start from the top-left corner and use Dijkstra's algorithm to explore neighboring cells, prioritizing those with lower effort. By iteratively updating the dist matrix and the priority queue, you eventually find the minimum effort path to the target cell.

The key insight here is that you explore cells with lower effort first, which ensures that you find the shortest path in terms of effort. This is a common approach when dealing with problems involving graphs or grids, where you want to find the minimum cost or effort path.
# Approach
<!-- Describe your approach to solving the problem. -->
Initialize the dist matrix to store the minimum effort required to reach each cell. Initialize it with INT_MAX except for the starting cell (0,0), which is set to 0 since no effort is needed to reach it.

Use a priority queue (minHeap) to keep track of cells to be explored. Cells are ordered in the priority queue based on their effort, with the smallest effort cell at the top.

Define the possible movement directions: right, left, down, and up. These directions are used to explore neighboring cells.

While the priority queue is not empty, do the following:

a. Pop the cell with the smallest effort from the priority queue.

b. If the current cell is the target cell (bottom-right corner), return the effort, as you have found the minimum effort path.

c. Skip this cell if you've already found a shorter path to it. This check ensures that you don't process the same cell multiple times.

d. Iterate through the possible directions and calculate the new effort to reach neighboring cells. The new effort is the maximum of the current effort and the absolute difference in heights between the current cell and the neighboring cell.

e. If the new effort is less than the previously stored effort for the neighboring cell, update the dist matrix and push the cell into the priority queue. This means you've found a shorter path to the neighboring cell, and you need to explore it further.

If the loop completes without reaching the target cell, return -1, indicating that there is no path to the target.
# Complexity
- Time complexity:-  O(rows * cols * log(rows * cols))
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:  O(rows*cols)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(0, 0, 0);

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!minHeap.empty()) {
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();

            // If you've reached the target, return the effort
            if (x == rows - 1 && y == cols - 1) {
                return effort;
            }

            // Skip this cell if you've already found a shorter path to it
            if (effort > dist[x][y]) {
                continue;
            }

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));

                    if (new_effort < dist[nx][ny]) {
                        dist[nx][ny] = new_effort;
                        minHeap.emplace(new_effort, nx, ny);
                    }
                }
            }
        }

        return -1; // If you reach here, there's no path to the target
    }
};

```*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(0, 0, 0);

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!minHeap.empty()) {
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();

            // If you've reached the target, return the effort
            if (x == rows - 1 && y == cols - 1) {
                return effort;
            }

            // Skip this cell if you've already found a shorter path to it
            if (effort > dist[x][y]) {
                continue;
            }

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));

                    if (new_effort < dist[nx][ny]) {
                        dist[nx][ny] = new_effort;
                        minHeap.emplace(new_effort, nx, ny);
                    }
                }
            }
        }

        return -1; // If you reach here, there's no path to the target
    }
};
