#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool bfs(unordered_map<int, vector<int>>& graph, int start, int goal) {
    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == goal) {
            return true;
        }
        visited.insert(node);
        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
            }
        }
    }
    return false;
}