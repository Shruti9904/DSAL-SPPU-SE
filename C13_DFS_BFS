#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;
    map<int, vector<int>> adjList;

public:
    Graph(int vertices) {
        this->V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // Assuming undirected graph
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Assuming undirected graph
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < V; ++i) {
            if (adjMatrix[v][i] && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int startNode) {
        vector<bool> visited(V, false);
        DFSUtil(startNode, visited);
        cout << endl;
    }

    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a map of the area around the college with landmarks as nodes
    map<string, int> landmarks;
    landmarks["Main Gate"] = 0;
    landmarks["Library"] = 1;
    landmarks["Cafeteria"] = 2;
    landmarks["Classroom Building"] = 3;
    landmarks["Sports Complex"] = 4;

    // Create a graph and add edges based on the map
    Graph g(5);
    g.addEdge(landmarks["Main Gate"], landmarks["Library"]);
    g.addEdge(landmarks["Main Gate"], landmarks["Cafeteria"]);
    g.addEdge(landmarks["Library"], landmarks["Classroom Building"]);
    g.addEdge(landmarks["Cafeteria"], landmarks["Classroom Building"]);
    g.addEdge(landmarks["Cafeteria"], landmarks["Sports Complex"]);
    g.addEdge(landmarks["Classroom Building"], landmarks["Sports Complex"]);

    cout << "DFS traversal starting from Main Gate: ";
    g.DFS(landmarks["Main Gate"]);

    cout << "BFS traversal starting from Main Gate: ";
    g.BFS(landmarks["Main Gate"]);

    return 0;
}

