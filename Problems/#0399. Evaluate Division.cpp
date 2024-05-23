// #0399. Evaluate Division
// https://leetcode.com/problems/evaluate-division/description/

#include<bits/stdc++.h>
using namespace std;

// Approach 2: Union-Find with Weights
// Let N be the number of input equations and M be the number of queries.
// Time Complexity: O((M+N)⋅logN), Space Complexity: O(N)

/*
    Algo
    Step 1): we iterate through each input equation, and invoke the union(dividend, divisor, quotient) 
    on each of them, in order to build the Union-Find data structure.
    Step 2): we evaluate the query one by one. The evaluation is just as intuitive as our first approach,
    which can be broken down into the following cases:
        case 1): Either of the variables did not appear in the input equations. 
        The query is not valid. We then return -1.0 as the result.
        case 2): If both variables are valid, we then apply the find(variable) 
        to obtain the tuple of (group_id, weight) for each variable. If they are not of the same group, 
        i.e. there is no chain of division between them, we then return -1.0 as the result.
        case 3): Finally if both variables are of the same group, then we simply perform the division 
        between their weights as the result.

*/

class Solution {
private:
    unordered_map<string, pair<string, double>> gidWeight;

    // Find function with path compression and weight update
    pair<string, double> find(const string& node) {
        if (gidWeight.find(node) == gidWeight.end()) {
            gidWeight[node] = {node, 1.0};
        }

        auto& entry = gidWeight[node];
        if (entry.first != node) {
            auto newEntry = find(entry.first);
            entry = {newEntry.first, entry.second * newEntry.second};
        }

        return gidWeight[node];
    }

    // Union function to join two sets
    void unionSets(const string& dividend, const string& divisor, double value) {
        auto dividendEntry = find(dividend);
        auto divisorEntry = find(divisor);

        string dividendGid = dividendEntry.first;
        string divisorGid = divisorEntry.first;
        double dividendWeight = dividendEntry.second;
        double divisorWeight = divisorEntry.second;

        if (dividendGid != divisorGid) {
            gidWeight[dividendGid] = {divisorGid, divisorWeight * value / dividendWeight};
        }
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        gidWeight.clear();  // Clear global state for safety

        // Step 1: Build union groups
        for (int i = 0; i < equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double val = values[i];
            unionSets(a, b, val);
        }

        // Step 2: Answer queries
        vector<double> results;
        for (const auto& q : queries) {
            const string& a = q[0];
            const string& b = q[1];

            if (!gidWeight.count(a) || !gidWeight.count(b)) {
                results.push_back(-1.0);
                continue;
            }

            auto rootA = find(a);
            auto rootB = find(b);

            if (rootA.first != rootB.first) {
                results.push_back(-1.0);
            } else {
                results.push_back(rootA.second / rootB.second);
            }
        }

        return results;
    }
};



// Approach 1: Path Search in Graph
// Time Complexity: O(M⋅N), Space Complexity: O(N)

/*

Intuition

First, let us look at the example given in the problem description.
Given two equations, namely ba​=2, cb​=3, we could derive the following equations:
    1). ab​=21​, bc​=31​
    2). ca​=ba​⋅cb​=2⋅3=6
Each division implies the reverse of the division, which is how we derive the equations in (1). While by chaining up equations, we could obtain new equations in (2).

    Note: We could reformulate the equations with the graph data structure, where each variable can be represented as a node in the graph,
    and the division relationship between variables can be modeled as edge with direction and weight.

The direction of edge indicates the order of division, and the weight of edge indicates the result of division.
With the above formulation, we then can convert the initial equations into the following graph:
graph example

        a/b=2 --->     b/c=3 --->
    a               b               c
        b/1=1/2 <--    c/b=1/3 <--

    Note: To evaluate a query (e.g. ca​=?) is equivalent to performing two tasks on the graph: 1). find if there exists a path between the two entities. 2). 
    if so, calculate the cumulative products along the paths.

In the above example (ca​=?), we could find a path between them, and the cumulative products are 6.
As a result, we can conclude that the result of ca​ is 2⋅3=6.

Algorithm
As one can see, we just transform the problem into a path searching problem in a graph.
    Note: More precisely, we can reinterpret the problem as "given two nodes, we are asked to check if there exists a path between them. 
    If so, we should return the cumulative products along the path as the result.
Given the above problem statement, it seems intuitive that one could apply the backtracking algorithm, or sometimes people might call it DFS (Depth-First Search).

Essentially, we can break down the algorithm into two steps overall:
    Step 1). we build the graph out of the list of input equations.
        Each equation corresponds to two edges in the graph.
    Step 2). once the graph is built, we then can evaluate the query one by one.
        The evaluation of the query is done via searching the path between the given two variables.
        Other than the above searching operation, we need to handle two exceptional cases as follows:
        Case 1): if either of the nodes does not exist in the graph, i.e. the variables did not appear in any of the input equations, then we can assert that no path exists.
        Case 2): if the origin and the destination are the same node, i.e. aa​, we can assume that there exists an invisible self-loop path for each node and the result is one.
*/

class Solution {
private:
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_set<string> visited;

    double dfs(const string& currNode, const string& targetNode, double accProduct) {
        visited.insert(currNode);

        // Direct path exists
        if (graph[currNode].count(targetNode)) {
            return accProduct * graph[currNode][targetNode];
        }

        // Explore neighbors
        for (const auto& neighbor : graph[currNode]) {
            if (visited.count(neighbor.first)) continue;

            double result = dfs(neighbor.first, targetNode, accProduct * neighbor.second);
            if (result != -1.0) return result;
        }

        return -1.0; // Path not found
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        graph.clear();

        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double val = values[i];
            graph[a][b] = val;
            graph[b][a] = 1.0 / val;
        }

        // Step 2: Process queries using DFS
        vector<double> results;
        for (const auto& query : queries) {
            const string& a = query[0];
            const string& b = query[1];

            if (!graph.count(a) || !graph.count(b)) {
                results.push_back(-1.0);
            } else if (a == b) {
                results.push_back(1.0);
            } else {
                visited.clear();
                results.push_back(dfs(a, b, 1.0));
            }
        }

        return results;
    }
};
