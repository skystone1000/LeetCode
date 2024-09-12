// #1584. Min Cost to Connect All Points
// https://leetcode.com/problems/min-cost-to-connect-all-points/

#include<bits/stdc++.h>
using namespace std;


// Approach 3: Prim's Algorithm (Optimized)
// If N is the number of points in the input array.
// Time complexity: O(N^2), Space complexity: O(N^2)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        int edgesUsed = 0;
        
        // Track nodes which are visited.
        vector<bool> inMST(n);
        
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        
        while (edgesUsed < n) {
            int currMinEdge = INT_MAX;
            int currNode = -1;
            
            // Pick least weight node which is not in MST.
            for (int node = 0; node < n; ++node) {
                if (!inMST[node] && currMinEdge > minDist[node]) {
                    currMinEdge = minDist[node];
                    currNode = node;
                }
            }
            
            mstCost += currMinEdge;
            edgesUsed++;
            inMST[currNode] = true;
            
            // Update adjacent nodes of current node.
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                if (!inMST[nextNode] && minDist[nextNode] > weight) {
                    minDist[nextNode] = weight;
                }
            }
        }
        
        return mstCost;
    }
};


// Approach 2: Prim's Algorithm
// Time complexity: O((N^2)⋅log(N)), Space complexity: O(N^2)
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Min-heap to store minimum weight edge at top -> pair<int, int> -> (edge weight, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
        // Track nodes which are included in MST.
        vector<bool> inMST(n);
        
        heap.push({ 0, 0 });
        int mstCost = 0;
        int edgesUsed = 0;
        
        while (edgesUsed < n) {
            pair<int, int> topElement = heap.top();
            heap.pop();
            
            int weight = topElement.first;
            int currNode = topElement.second;
            
            // If node was already included in MST we will discard this edge.
            if (inMST[currNode]) {
                continue;
            }
            
            inMST[currNode] = true;
            mstCost += weight;
            edgesUsed++;
            
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                // If next node is not in MST, then edge from curr node
                // to next node can be pushed in the priority queue.
                if (!inMST[nextNode]) {
                    int nextWeight = abs(points[currNode][0] - points[nextNode][0]) + 
                                     abs(points[currNode][1] - points[nextNode][1]);
                    
                    heap.push({ nextWeight, nextNode });
                }
            }
        }
        
        return mstCost;
    }
};

//==============================================================
// Implementation in explore card
class Edge {
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};
// Overload the < operator.
bool operator<(const Edge& edge1, const Edge& edge2) {
    return edge1.cost > edge2.cost;
}

class Solution {
public:
    // Prim's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int sz = points.size();
        priority_queue<Edge> pq;
        vector<bool> visited(sz);
        int result = 0;
        int count = sz - 1;
        // Add all edges from points[0] vertex
        vector<int>& coordinate1 = points[0];
        for (int j = 1; j < sz; j++) {
            // Calculate the distance between two coordinates
            vector<int>& coordinate2 = points[j];
            int cost = abs(coordinate1[0] - coordinate2[0]) +
                       abs(coordinate1[1] - coordinate2[1]);
            Edge edge(0, j, cost);
            pq.push(edge);
        }
        visited[0] = true;

        while (!pq.empty() && count > 0) {
            Edge edge = pq.top();
            pq.pop();
            int point1 = edge.point1;
            int point2 = edge.point2;
            int cost = edge.cost;
            if (!visited[point2]) {
                result += cost;
                visited[point2] = true;
                for (int j = 0; j < sz; j++) {
                    if (!visited[j]) {
                        int distance = abs(points[point2][0] - points[j][0]) +
                                       abs(points[point2][1] - points[j][1]);
                        pq.push(Edge(point2, j, distance));
                    }
                }
                count--;
            }
        }
        return result;
    }
};


// Approach 1: Kruskal's Algorithm + Disjoint Set
// If N is the number of points in the input array.
// Time complexity: O((N^2)⋅log(N)), Space complexity: O(N^2)
class Edge {
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};

// Overload the < operator.
bool operator<(const Edge& edge1, const Edge& edge2) {
    return edge1.cost > edge2.cost;
}

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    // Kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int sz = points.size();
        priority_queue<Edge> pq;
        UnionFind uf(sz);

        for (int i = 0; i < sz; i++) {
            vector<int>& coordinate1 = points[i];
            for (int j = i + 1; j < sz; j++) {
                vector<int>& coordinate2 = points[j];
                // Calculate the distance between two coordinates.
                int cost = abs(coordinate1[0] - coordinate2[0]) +
                           abs(coordinate1[1] - coordinate2[1]);
                Edge edge(i, j, cost);
                pq.push(edge);
            }
        }

        int result = 0;
        int count = sz - 1;
        while (!pq.empty() && count > 0) {
            Edge edge = pq.top();
            pq.pop();
            if (!uf.connected(edge.point1, edge.point2)) {
                uf.unionSet(edge.point1, edge.point2);
                result += edge.cost;
                count--;
            }
        }
        return result;
    }
};


// Approach 0: Customized Disjoint Set + Kruskal
// Runtime: 1357 ms, faster than 18.33% of C++ online submissions for Min Cost to Connect All Points.
// Memory Usage: 177.2 MB, less than 10.63% of C++ online submissions for Min Cost to Connect All Points.
class Solution {
public:
    int getParent(vector<int>& parents, int idx){
        if(parents[idx] == idx)
            return idx;
        
        parents[idx] = getParent(parents, parents[parents[idx]]);
        return parents[idx];
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0);
        int ans = 0;
        int edges = 0;
        priority_queue<vector<int>> pq;
        
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(i!=j)
                    pq.push({-1*( abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) ) , i , j });
        
        while(edges != n-1){
            vector<int> edge = pq.top();
            int p1 = getParent(parents, edge[1]);
            int p2 = getParent(parents, edge[2]);
            if(p1 != p2){
                ans += -1*edge[0];
                parents[p1] = p2;
                edges++;
            }
            pq.pop();
        }
        
        return ans;
    }
};