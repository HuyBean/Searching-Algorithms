#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool dfs(unordered_map<int, vector<int>>& graph, int start, int goal, unordered_set<int>& visited) {
    visited.insert(start);
    if (start == goal) {
        return true;
    }
    for (int neighbor : graph[start]) {
        if (visited.find(neighbor) == visited.end()) {
            if (dfs(graph, neighbor, goal, visited)) {
                return true;
            }
        }
    }
    return false;
}
