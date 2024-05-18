// #0332. Reconstruct Itinerary
// https://leetcode.com/problems/reconstruct-itinerary/description/

#include<bits/stdc++.h>
using namespace std;


// Approach 1: Iterative Hierholzer’s Algorithm for Eulerian Path
// Time: O(E log E) - E = number of tickets, Space: O(E)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> newItinerary;
        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string currentAirport = st.top();

            if (graph.find(currentAirport) != graph.end() && !graph[currentAirport].empty()) {
                st.push(graph[currentAirport].top());
                graph[currentAirport].pop();
            } else {
                newItinerary.push_back(st.top());
                st.pop();
            }
        }

        reverse(newItinerary.begin(), newItinerary.end());
        return newItinerary;        
    }
};


// Approach 2: DFS Hierholzer’s Algorithm (Lexical Ordered DFS/Eulerian Path)
// Time: O(E log E) due to heap operations (E = number of tickets), Space: O(E)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        vector<string> itinerary;
        dfs("JFK", graph, itinerary);
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }

private:
    void dfs(const string& airport,
             unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph,
             vector<string>& itinerary) {
        auto& dests = graph[airport];
        while (!dests.empty()) {
            string next = dests.top(); dests.pop();
            dfs(next, graph, itinerary);
        }
        itinerary.push_back(airport);
    }
};
