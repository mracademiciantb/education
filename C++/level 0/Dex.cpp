#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_distance > dist[current_vertex]) {
            continue;
        }

        for (const auto& edge : graph[current_vertex]) {
            int to = edge.first;
            int length = edge.second;

            if (dist[current_vertex] + length < dist[to]) {
                dist[to] = dist[current_vertex] + length;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) {
            cout << "Distance from " << start << " to " << i << " is : INF" << endl;
        } else {
            cout << "Distance from " << start << " to " << i << " is : " << dist[i] << endl;
        }
    }
}

int main() {
    // Приклад графа, описаного в попередньому прикладі
    int n = 5; // Кількість вершин
    vector<vector<pair<int, int>>> graph(n);

    // Додаємо ребра (ненаправлений граф для спрощення)
    // A = 0, B = 1, C = 2, D = 3, E = 4
    graph[0].push_back({1, 4}); // A-B
    graph[0].push_back({2, 2}); // A-C
    graph[1].push_back({2, 5}); // B-C
    graph[1].push_back({3, 10}); // B-D
    graph[2].push_back({3, 3}); // C-D
    graph[2].push_back({4, 4}); // C-E
    graph[3].push_back({4, 1}); // D-E

    // Запускаємо алгоритм Дейкстри з вершини A, яка має індекс 0
    dijkstra(graph, 0);

    return 0;
}
