#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V; // Кількість вузлів
    list<int> *adj; // Покажчик на масив, що містить списки суміжності

    // Функція рекурсивного DFS обходу
    void DFSUtil(int v, vector<bool> &visited) {
        // Позначаємо поточний вузол як відвіданий і виводимо його
        visited[v] = true;
        cout << v << " ";

        // Перебір усіх вершин, суміжних з цією вершиною
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }

public:
    Graph(int V) { // Конструктор
        this->V = V;
        adj = new list<int>[V];
    }

    // Додавання ребра до графа
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Додати w до списку v.
    }

    // Функція DFS обходу, яка використовує DFSUtil()
    void DFS(int v) {
        // Спочатку позначаємо усі вершини як не відвідані
        vector<bool> visited(V, false);

        // Виклик рекурсивної допоміжної функції для обходу DFS
        DFSUtil(v, visited);
    }
};

int main() {
    // Створення графа
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Обхід в глибину (починаючи з вершини 2):" << endl;
    g.DFS(2);

    return 0;
}