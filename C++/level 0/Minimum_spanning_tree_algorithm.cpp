#include <cstdlib>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <ctime> 
#include <queue>
#include <fstream>
#include <string>
#include <utility>

const int MAX = std::numeric_limits<int>::max();

class DisjointSets {
    std::vector<int> parent, rank;

public:
    DisjointSets(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
};

class graph{
public:
    int size;
    std::vector<std::pair<int, std::pair<int, int>>> edges; // (weight, (u, v))

    graph(std::string filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << std::endl;
            exit(1);
        }

        file >> size;
        int u, v, cost;
        while (file >> u >> v >> cost) {
            edges.push_back({cost, {u, v}});
        }
    }

    std::vector<std::pair<int, int>> kruskalMST() {
        int mst_weight = 0;
        DisjointSets ds(size);
        std::vector<std::pair<int, int>> mst;

        sort(edges.begin(), edges.end());

        for (auto& edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.find(u) != ds.find(v)) {
                mst.push_back({u, v});
                mst_weight += weight;
                ds.unite(u, v);
            }
        }

        std::cout << "Total weight of MST: " << mst_weight << std::endl;
        return mst;
    }
};

int main() {
    graph obj("graph.txt");
    auto mst = obj.kruskalMST();

    for (auto& edge : mst) {
        std::cout << "Edge from " << edge.first << " to " << edge.second << std::endl;
    }

    return 0;
}
