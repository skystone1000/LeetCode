// #0261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Advanced Graph Theory + Union Find
// Let E be the number of edges, and N be the number of nodes.
// Time Complexity : O(N⋅α(N)) , Space Complexity : O(N)
/*
    Intution for approach 3 and 2
    For the graph to be a valid tree, it must have exactly n - 1 edges. Any less, and it can't possibly be fully connected. 
    Any more, and it has to contain cycles. Additionally, if the graph is fully connected and contains exactly n - 1 edges, 
    it can't possibly contain a cycle, and therefore must be a tree!

    Going by this definition, our algorithm needs to do the following:
        1) Check whether or not there are n - 1 edges. If there's not, then return false.
        2) Check whether or not the graph is fully connected. Return true if it is, false if otherwise.

    Recall that the most complicated part of Approach 1 was in checking whether or not the graph contained cycles. 
    This was because in an undirected graph, we needed to be careful of trivial cycles. Checking whether or not a graph 
    is fully connected is straightforward—we simply checked if all nodes were reachable from a search starting at a single node.

    Like before, we can check for connectivity using recursive depth-first search, iterative depth-first search, or 
    iterative breadth-first search. We still need to use a seen set to prevent the algorithm from getting caught 
    in an infinite loop if there are indeed cycles (and to prevent looping on the trivial cycles).

*/
class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = find(parent[node]);
    }

    bool unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return false; // already connected

        // Union by size
        if (size[rootA] < size[rootB]) {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        } else {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // Condition 1: Must have exactly n - 1 edges
        if (edges.size() != n - 1) return false;

        UnionFind uf(n);
        for (auto& edge : edges) {
            if (!uf.unionSet(edge[0], edge[1])) {
                // Cycle detected
                return false;
            }
        }

        // If no cycle and n - 1 edges, it's a valid tree
        return true;
    }
};


// Approach 2: Advanced Graph Theory + Iterative Depth-First Search + Breadth-first search
// Time Complexity : O(N) , Space Complexity : O(N)

// a) Iterative Depth-First Search.
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        // Make the adjacency list.
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        stack<int> stk;
        unordered_set<int> seen;
        stk.push(0);
        seen.insert(0);

        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();

            for (int neighbor : adjacencyList[node]) {
                if (seen.count(neighbor)) continue;
                seen.insert(neighbor);
                stk.push(neighbor);
            }
        }

        return seen.size() == n;
    }
};

// b) Recursive Depth-First Search.
class Solution {
public:
    vector<vector<int>> adjacencyList;
    unordered_set<int> seen;

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        // Make the adjacency list.
        adjacencyList.resize(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Carry out depth first search.
        dfs(0, -1);

        // Inspect result and return the verdict.
        return seen.size() == n;
    }

    void dfs(int node, int parent) {
        if (seen.count(node)) return;
        seen.insert(node);
        for (int neighbor : adjacencyList[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node);
            }
        }
    }
};


// c) Iterative Breadth-First Search.
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        // Build the adjacency list
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        unordered_set<int> seen;

        q.push(0);
        seen.insert(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjacencyList[node]) {
                if (seen.count(neighbor)) continue;
                seen.insert(neighbor);
                q.push(neighbor);
            }
        }

        return seen.size() == n;
    }
};



// Approach 1: Graph Theory + Iterative Depth-First Search + 
// Time Complexity : O(N+E) , Space Complexity : O(N+E)
/*
    Intution
    Depth-first search is a classic graph-traversal algorithm that can be used to check for both of these conditions:
    1) G is fully connected if, and only if, we started a depth-first search from a single source and discovered all nodes in G during it.
    2) G contains no cycles if, and only if, the depth-first search never goes back to an already discovered node. 
    We need to be careful though not to count trivial cycles of the form A → B → A that occur with most implementations of undirected edges.
*/

// a) Iterative DFS with a stack
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // This detects cycle already if only single component, but still adding cycle code for approach
        if (edges.size() != n - 1) return false; // Quick check for number of edges

        // Build the adjacency list
        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> parent;
        parent[0] = -1;
        stack<int> stk;
        stk.push(0);

        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();

            for (int neighbor : adjacencyList[node]) {
                if (parent[node] == neighbor) {
                    continue;
                }
                if (parent.count(neighbor)) {
                    // Found a cycle
                    return false;
                }
                parent[neighbor] = node;
                stk.push(neighbor);
            }
        }

        // If all nodes are connected, parent map should contain all nodes
        return parent.size() == n;
    }
};

// b) Recursive DFS
class Solution {
public:
    vector<vector<int>> adjacencyList;
    unordered_set<int> seen;

    bool validTree(int n, vector<vector<int>>& edges) {
        // This detects cycle already if only single component, but still adding cycle code for approach
        if (edges.size() != n - 1) return false;

        adjacencyList.resize(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        // Start DFS from node 0
        return dfs(0, -1) && seen.size() == n;
    }

    bool dfs(int node, int parent) {
        if (seen.count(node)) return false;

        seen.insert(node);
        for (int neighbor : adjacencyList[node]) {
            if (neighbor == parent) continue;
            if (!dfs(neighbor, node)) return false;
        }

        return true;
    }
};

// c) Breadth-first search
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // This detects cycle already if only single component, but still adding cycle code for approach
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adjacencyList(n);
        for (const auto& edge : edges) {
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> parent;
        parent[0] = -1;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjacencyList[node]) {
                if (parent[node] == neighbor) continue;
                if (parent.count(neighbor)) return false;
                q.push(neighbor);
                parent[neighbor] = node;
            }
        }

        return parent.size() == n;
    }
};
