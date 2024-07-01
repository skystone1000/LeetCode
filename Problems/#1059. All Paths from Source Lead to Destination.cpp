// #1059. All Paths from Source Lead to Destination
// https://leetcode.com/problems/all-paths-from-source-lead-to-destination/description/
// Company Tag - Google

#include<bits/stdc++.h>
using namespace std;

// Approach 1: Depth First Search
/*
    Intuition
    - This is one of the most common graph traversal techniques out there which makes 
    use of the stack data structure. As mentioned in the overview section above, 
    we simply need to run a graph traversal algorithm and check for two basic conditions. 
    It is easy enough to check for a leaf node since the adjacency list entry for that 
    node would not contain any neighbors. So our first condition can be easily checked 
    i.e. if we encounter a leaf node, we check its equality to the destination node.
    - As for cycle detection, there are multiple ways one can go about modifying 
    the standard DFS algorithm. We will be following the node-coloring variant of 
    the algorithm which is explained in the Introduction to Algorithms (CLRS) book. 
    The idea is to do DFS of a given graph and while doing traversal, assign 
    one of the below three colors to every vertex. According to the algorithm 
    mentioned in the book, there are three different colors we can assign a node:
    a) WHITE ~ Vertex is not processed yet. Initially, all vertices are WHITE.
    b) GRAY ~ Vertex is being processed (DFS for this vertex has started, 
    but not finished which means that all descendants (in DFS tree) of this vertex 
    are not processed yet (or this vertex is in the function call stack).
    c) BLACK ~ Vertex and all its descendants are processed.

    While doing DFS, if an edge is encountered from current vertex to a GRAY vertex, 
    then this edge is a back edge and hence there is a cycle. A GRAY node represents 
    a node whose processing is still ongoing. Thus, if a descendent eventually 
    leads back to a node whose processing is ongoing, it ends up creating a cycle in the 
    directed graph and we call the edge leading back to a GRAY node as a backward edge.
*/
// Time complexity: O(V)
// Space Complexity: O(V+E) where O(E) is occupied by the adjacency list and O(V) is occupied by the recursion stack and the color state
class Solution {
public:
    enum Color { GRAY, BLACK };

    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build directed graph as adjacency list
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        // Use optional<Color> as C++ doesn't support nullable enum directly
        vector<int> state(n, -1); // -1 = WHITE (unvisited), 0 = GRAY, 1 = BLACK

        return dfs(graph, source, destination, state);
    }

private:
    bool dfs(vector<vector<int>>& graph, int node, int dest, vector<int>& state) {
        if (state[node] != -1) return state[node] == BLACK;
        
        // If it's a leaf node, it must be the destination
        if (graph[node].empty()) return node == dest;
        
        // Mark node as GRAY
        state[node] = GRAY;

        for (int neighbor : graph[node]) 
            if (!dfs(graph, neighbor, dest, state)) 
                return false;
            
        // Mark node as BLACK after all paths are validated
        state[node] = BLACK;
        return true;
    }
};


// Another Implementation
class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& e : edges)
            graph[e[0]].push_back(e[1]);

        vector<int> color(n, 0); // 0=unvisited, 1=visiting, 2=safe
        return dfs(source, graph, color, destination);
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int dest) {
        if (graph[node].empty()) return node == dest; // must end at dest
        if (color[node] == 1) return false; // cycle detected
        if (color[node] == 2) return true; // already proven safe

        color[node] = 1; // visiting
        for (int nei : graph[node]) {
            if (!dfs(nei, graph, color, dest)) return false;
        }
        color[node] = 2; // safe
        return true;
    }
};


// Approach 2: BFS

/*
    A BFS could be reasonable if the graph is undirected (be my guest at showing an 
    efficient algorithm using BFS that would report the cycles in a directed graph!), 
    where each cross edge defines a cycle (edge going from a node to an already visited node). 
    If the cross edge is {v1, v2}, and the root (in the BFS tree) that contains those nodes is r, 
    then the cycle is r ~ v1 - v2 ~ r (~ is a path, - a single edge), which can be reported 
    almost as easily as in DFS.
    
    The only reason to use a BFS would be if you know your (undirected) graph is going to 
    have long paths and small path cover (in other words, deep and narrow). In that case, 
    BFS would require proportionally less memory for its queue than DFS' stack 
    (both still linear of course).
    
    In all other cases, DFS is clearly the winner.
*/