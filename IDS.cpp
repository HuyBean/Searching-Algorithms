#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool dls(unordered_map<int, vector<int>>& graph, int start, int goal, int depth, unordered_set<int>& visited) {
    visited.insert(start);
    if (start == goal) {
        return true;
    }
    if (depth == 0) {
        return false;
    }
    for (int neighbor : graph[start]) {
        if (visited.find(neighbor) == visited.end()) {
            if (dls(graph, neighbor, goal, depth - 1, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool ids(unordered_map<int, vector<int>>& graph, int start, int goal, int max_depth) {
    unordered_set<int> visited;
    for (int depth = 0; depth <= max_depth; depth++) {
        visited.clear();
        if (dls(graph, start, goal, depth, visited)) {
            return true;
        }
    }
    return false;
}
