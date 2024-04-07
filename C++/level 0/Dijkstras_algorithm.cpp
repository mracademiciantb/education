/*
I ask you to give this code a fair assessment. 
I am very bad at writing C++. 
If I have failed in the task, please point out the errors and ways to fix them, 
I will be very grateful.
*/
#include <cstdlib>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
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
            graphVector.resize(size);
            int edgesToCreate = static_cast<int>(densityPercentage * max_edges);

            for(int i = 0; i < edgesToCreate; i++) {
                int u = rand() % size;
                int v = rand() % size;
                if(u != v) {
                    float weight = minWeight + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(maxWeight - minWeight)));
                    int intWeight = static_cast<int>(weight);
                    graphVector[u].push_back({v, intWeight});
                    graphVector[v].push_back({u, intWeight});
                }
            }
        }

        std::vector<int> dijkstra(int start) {
            std::vector<int> dist(size, MAX);
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
            }
            return dist;
        }
};

int main() {
    graph obj;
    obj.fillVector();
    std::vector<int> dist = obj.dijkstra(0);

    int sum = 0;
    int reachableNodes = 0;
    for(int t = 0; t < obj.size; t++) {
        if(dist[t] < MAX) {
            sum += dist[t];
            reachableNodes++;
        }
    }

    for (int i = 0; i < obj.size; ++i) {
        if (dist[i] == MAX) {
            std::cout << "Distance from 0 to " << i << " is: MAX" << std::endl;
        } else {
            std::cout << "Distance from 0 to " << i << " is: " << dist[i] << std::endl;
        }
    }

    int ans = (reachableNodes > 0) ? sum / reachableNodes : 0;
    std::cout << "Average distance: " << ans << std::endl;

    return 0;
}