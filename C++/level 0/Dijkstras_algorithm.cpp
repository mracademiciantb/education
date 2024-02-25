#include <cstdlib>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include <queue>
#include <utility>


const int MAX = std::numeric_limits<int>::max();

class graph{
    public:
        int size = 50;
        int max_edges = size * (size - 1) / 2;
        float densityPercentage = 0.20;
        float densityMax_edges = max_edges * densityPercentage;
        float minWeight = 0.1;
        float maxWeight = 10.0;

        std::vector<std::vector<std::pair<int, int>>> graphVector;

        void fillVector() {
            srand(time(NULL)); 
            graphVector.resize(size); // Initialising a vector
            int edgesToCreate = static_cast<int>(densityPercentage * max_edges);

            for(int i = 0; i < edgesToCreate; i++) {
            int u = rand() % size;
            int v = rand() % size;
            if(u != v) {
                float weight = minWeight + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maxWeight - minWeight)));
                graphVector[u].push_back({v, weight});
                graphVector[v].push_back({u, weight}); // For an undirected graph
        }
    }
}

        // Search algorithm (Dijkstra)
void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graphVector, int start) {
            int n = graphVector.size();
            std::vector<int> dist(n, MAX);
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_distance > dist[current_vertex]) {
            continue;
        }

        for (const auto& edge : graphVector[current_vertex]) {
            int to = edge.first;
            int length = edge.second;

            if (dist[current_vertex] + length < dist[to]) {
                dist[to] = dist[current_vertex] + length;
                pq.push({dist[to], to});
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (dist[i] == MAX) {
            std::cout << "Distance from " << start << " to " << i << " is : MAX" << std::endl;
        } else {
            std::cout << "Distance from " << start << " to " << i << " is : " << dist[i] << std::endl;
        }
    }
}

};


int main(){
        graph obj;
        obj.fillVector();
        obj.dijkstra(obj.graphVector, 0);

    return 0;
}