/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
Example 1:
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:
Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
Intuition
The intuition behind the code I provided for finding a valid itinerary using given flight tickets is to treat the problem as a graph traversal problem and use depth-first search (DFS) to explore all possible routes through the graph

Approach
Graph Construction: The code constructs a graph representation of flight connections using an unordered map (graph) where airports are keys, and their destinations are stored in a multiset. This graph-building step organizes the tickets into a structured form for further processing.

DFS Traversal with Stack: It employs a depth-first search (DFS) algorithm using an explicitly managed stack (dfs). The DFS starts from the "JFK" airport and explores the possible flight routes through the graph.

Ticket Utilization: During the DFS traversal, the code considers and removes each ticket (flight connection) as it explores destinations. This ensures that each ticket is used exactly once.

Itinerary Formation: As the DFS progresses, the code constructs an itinerary in reverse order. When it reaches an airport with no more available destinations, it adds that airport to the itinerary. At the end, the itinerary is reversed to obtain the correct order.

Data Structures: The code uses data structures like unordered maps, multisets, and stacks to facilitate graph representation, DFS traversal, and itinerary construction.

Complexity
Time complexity:- O(n)
Space complexity: O(n)
*/


class Solution {
public:
        vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        vector<string> itinerary;

        // Build the graph using the given tickets
        for (const vector<string>& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        stack<string> dfs;
        dfs.push("JFK");  // Starting from JFK airport

        while (!dfs.empty()) {
            string airport = dfs.top();

            if (graph.find(airport) != graph.end() && !graph[airport].empty()) {
                // If there are destinations from this airport, push the next destination onto the stack
                dfs.push(*(graph[airport].begin()));
                graph[airport].erase(graph[airport].begin());
            } else {
                // If there are no more destinations from this airport, add it to the itinerary
                itinerary.push_back(airport);
                dfs.pop();
            }
        }

        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }

};