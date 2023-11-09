#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool hasPath(unordered_map<int, unordered_set<int>>& graph, int source, int destination, unordered_set<int>& visited){
    if(source == destination) return true;

    visited.insert(source);
    
    for(int neighbor : graph[source]){
        if(visited.find(neighbor) == visited.end()){
            if(hasPath(graph, neighbor, destination, visited)) return true;
        }
    }
    return false;
}

bool hasValidPath(vector<vector<int>>& edges, int n, int source, int destination){
    unordered_map<int, unordered_set<int>> graph;

    for(const vector<int>& edge : edges){
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }
    unordered_set<int> visited;
    return hasPath(graph, source, destination, visited);
}

int main(){
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    int n = 4;
    int source = 0;
    int destination = 3;
    
    bool result = hasValidPath(edges, n, source, destination);
    
    if (result) {
        cout << "There is a valid path from source to destination." << endl;
    } else {
        cout << "There is no valid path from source to destination." << endl;
    }
    
    return 0;
}