#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool ucs(unordered_map<int, unordered_map<int, int>>& graph, int start, int goal) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_set<int> visited;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (node == goal) {
            return true;
        }
        visited.insert(node);
        for (auto neighbor : graph[node]) {
            int neighbor_node = neighbor.first;
            int neighbor_cost = neighbor.second;
            if (visited.find(neighbor_node) == visited.end()) {
                pq.push({cost + neighbor_cost, neighbor_node});
            }
        }
    }
    return false;
}
