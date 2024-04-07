#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V; // number of nodes
    list<int> *adj; // A pointer to an array containig adjaency lists

    // Recursive DFS traversal function
    void DFStil(int v, vector<bool> &visited) {
        // Mark the current node as visited and dispaly it
        visited[v] = true;
        cout << v << " ";

        // Enumerate all nodes adjacent to this node
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if(!visited[*i])
                DFStil(*i, visited);
    }

public:
    Graph(int V) { // Counstructor
        this->V = V;
        adj = new list<int>[V];
    }

    // Adding an edge to a graph
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to the list of v
    }

    // A DFS bypass function that uses DFSUtil()
    void DFS(int v) {
        // First mark all nodes as unvisited
        vector<bool> visited(V, false);

        // Calling recursive helper function to bypass DF
        DFStil(v, visited);
    }
};

int main() {
    // Creating a graph
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Going deep (starting from vertex 2): " << endl;
    g.DFS(2);

    return 0;
}