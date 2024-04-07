//Homework3 (min Spanning tree)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <random>
#include <cmath>
#include <fstream>

using namespace std;

class Graph {
private:
    int num_nodes;
    unordered_map<int, vector<pair<int, double>>> adj_list;

public:
    Graph(int n) : num_nodes(n) {}

    Graph(const string& filename) {
        ifstream infile(filename);
        if (!infile.is_open()) {
            cerr << "Error opening file " << filename << endl;
            return;
        }

        infile >> num_nodes;

        int u, v;
        double weight;
        while (infile >> u >> v >> weight) {
            addEdge(u, v, weight);
        }

        infile.close();
    }

    void addEdge(int u, int v, double weight) {
        adj_list[u].push_back({v, weight});
        adj_list[v].push_back({u, weight});
    }

    vector<pair<int, int>> primMST() {
        vector<bool> visited(num_nodes + 1, false);
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        vector<pair<int, int>> mst_edges;

        visited[1] = true;
        for (auto& [v, w] : adj_list[1]) {
            pq.push({w, v});
        }

        while (!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;
            mst_edges.push_back({u, u}); // parent and child (u, parent)

            for (auto& [v, weight] : adj_list[u]) {
                if (!visited[v]) {
                    pq.push({weight, v});
                }
            }
        }

        return mst_edges;
    }

    void printMST(const vector<pair<int, int>>& mst_edges) {
        cout << "Minimum Spanning Tree Edges:" << endl;
        double total_weight = 0.0;
        for (const auto& [u, v] : mst_edges) {
            cout << u << " - " << v << endl;
            for (const auto& [vertex, weight] : adj_list[u]) {
                if (vertex == v) {
                    total_weight += weight;
                    break;
                }
            }
        }
        cout << "Total weight of Minimum Spanning Tree: " << total_weight << endl;
    }
};

int main() {
    // Example usage
    Graph graph("graph_data.txt");

    cout << "Graph read from file." << endl;

    auto mst_edges = graph.primMST();
    graph.printMST(mst_edges);

    return 0;
}