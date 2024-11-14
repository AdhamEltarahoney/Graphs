#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Graph {
    int vertices; // Number of vertices
    std::vector<std::vector<int>> adjList; // Adjacency list

public:
    Graph(int V) : vertices(V), adjList(V) {}

    // Add edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph, add both directions
    }

    // BFS function
    void BFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> queue;
        
        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            int node = queue.front();
            queue.pop();
            std::cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
    }

    // DFS function
    void DFS(int start) {
        std::vector<bool> visited(vertices, false);
        std::stack<int> stack;
        
        stack.push(start);

        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            if (!visited[node]) {
                visited[node] = true;
                std::cout << node << " ";
            }

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    std::cout << "BFS starting from node 0: ";
    g.BFS(0);
    std::cout << "\n";

    std::cout << "DFS starting from node 0: ";
    g.DFS(0);
    std::cout << "\n";

    return 0;
}
