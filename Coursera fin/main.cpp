// Victoria Kondratieva
// Unordered graph representation:
// I am using adjacency list implementation because the density of the graph is
// low (20% and 40%). Sparse matrix will have a lot of 0s and it's a waste of
// memory.
// For the data structures, I am using unordered_map where key is the node and 
// value is the vector of pairs <node, edge cost>.

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>
#include <set>
#include <tuple>

class Graph {
       public:
       // default constructor
       Graph()= default;

       // create a graph with n nodes, cost range: min and max, and density as parameters
       Graph(int n, int min, int max, double density) {
           // add n number of nodes from 0 to n-1
           num_nodes_ = n;
           for(int i = 0; i < n; ++i) {
               add_node(i);
           }
           // add edges at random. Generate a random num between [0,1].
           // If num is less than or equals to density, add the edge.
           // Otherwise ignore the edge.
           // Use random generator for the cost
           std::default_random_engine generator;
           std::uniform_real_distribution<double> density_val(0, 1);
           std::uniform_int_distribution<int> cost_val(min, max);
           auto generate_density = std::bind(density_val, generator);
           auto generate_cost = std::bind(cost_val, generator);
           for(int i = 0; i < n; ++i) {
               for(int j = 0; j < i; ++j) {
                   if (i != j){
                       if(generate_density() <= density){
                           add_edge(i, j, generate_cost());
                       }
                   }
               }
           }

       }

       // constructor to support reading from a file
       Graph(const std::string& file_name){
           std::ifstream input_file;
           input_file.open(file_name);
           int num_nodes, node_A, node_B, cost;
           // read in the number of nodes and add them to the graph
           input_file >> num_nodes;
           num_nodes_ = num_nodes;
           for (int i = 0; i < num_nodes; ++i){
               add_node(i);
           }

           while (input_file >> node_A >> node_B >> cost) {
               add_edge(node_A, node_B, cost);

           }

       }


       void add_node(int new_node) {
              if (!graph_map_.count(new_node)){
                    std::vector<std::pair<int, int> > v;
                    graph_map_.insert(std::make_pair(new_node, v ));
              } 
       }
                     
       bool edge_exists(int node_A, int node_B){
           assert(graph_map_.count(node_A) && graph_map_.count(node_B));
           for(auto item : graph_map_.at(node_A)) {
                if (item.first == node_B){
                    return true;
                }
           }
           return false;
       }

       int edge_cost(int node_A, int node_B){
           for(auto item : graph_map_.at(node_A)) {
               if (item.first == node_B){
                   return item.second;
               }
           }
           return -1;
       }
       
       void add_edge(int node_A, int node_B, int cost) {
           assert(graph_map_.count(node_A) && graph_map_.count(node_B));
           graph_map_.at(node_A).push_back(std::make_pair(node_B, cost));
           graph_map_.at(node_B).push_back(std::make_pair(node_A, cost));
           // for Prim's additional mapping
           // if is no key created yet, set up the mapping and add the key.
           if (edge_cost_map_.count(cost) == 0){
               std::vector< std::pair<int, int> > v;
               edge_cost_map_[cost].push_back(std::make_pair(node_A, node_B));
           } else{
               edge_cost_map_.at(cost).push_back(std::make_pair(node_A, node_B));

           }
           cost_list_.push_back(cost);
       }

       [[nodiscard]] std::vector<std::pair<int, int> > get_neighbors(int node) const{
           assert(graph_map_.count(node) != 0);
           return graph_map_.at(node);

       }

    [[nodiscard]] std::unordered_map <int, std::vector<std::pair<int, int> > > get_map() const {
        return graph_map_;
    }

    [[nodiscard]] std::unordered_map <int, std::vector<std::pair<int, int> > > get_cost_map() const {
        return edge_cost_map_;
    }

    [[nodiscard]] std::vector<int> get_cost_list() const {
        return cost_list_;
    }

    int get_num_nodes() const {
        return num_nodes_;
    }

       // overloaded << operator is a friend function - has access to the private members of the Graph class
       friend std::ostream& operator<< (std::ostream& os, const Graph& g){
           std::cout << "Graph " << std::endl;
           for(const auto& item : g.graph_map_){
               std::cout << item.first << ": ";
               for (const auto& node_pair : item.second) {
                   std::cout << "(" << node_pair.first << ", " << node_pair.second << ") ";
               }
               std::cout << std::endl;
           }

           return os;
       }


       private:
           // mapping from nodeA to neighbors <NodeB, cost>
       std::unordered_map <int, std::vector<std::pair<int, int> > > graph_map_;
       // mapping from cost to list of edges: <nodeA, nodeB>
       std::unordered_map <int, std::vector<std::pair<int, int> > > edge_cost_map_;
       int num_nodes_;
       std::vector<int> cost_list_;


};

class DijstrasShortestPath {
public:
    int shortest_path(const Graph& g, int start_node, int end_node){
        // visit the first node and let it's neighbors be unvisited_.
        // assign 0 to the cost of the start node to itself.
        cost_map_[start_node] = 0;
        parent_map_[start_node] = -1;
        int parent_node = start_node;
        while (true){
            //get the neighbors of a node
            std::vector<std::pair<int, int> > neighbors = g.get_neighbors(parent_node);
            for(auto item : neighbors){

                // if new element, add cost and parent information
                if (cost_map_.count(item.first) == 0) {
                    parent_map_[item.first] = parent_node;
                    cost_map_[item.first] = item.second + cost_map_.at(parent_map_.at(item.first));
                } else{
                    // if the new cost is smaller than the previous cost, update the cost and parent maps
                    if (item.second + cost_map_.at(parent_node) < cost_map_.at(item.first)){
                        parent_map_[item.first] = parent_node;
                        cost_map_[item.first] = item.second + cost_map_.at(parent_map_.at(item.first));

                    }
                }

                if (visited_.count(item.first) == 0){
                    unvisited_.push_back(item.first);
                }

            }
            visited_.insert(parent_node);

            // once we don't have any unvisited_ nodes to explore, we are done.
            if (unvisited_.empty()) {
                break;
            }

            // pick the next node to be visited_ from the unvisited_ list
            parent_node = unvisited_.back();
            unvisited_.pop_back();

        }

//        // print the parent-child mapping for debug
//        std::cout << "Parent Map" << std::endl;
//        for (auto item : parent_map_) {
//            std::cout << "parent: " << item.second << ", child:" << item.first << std::endl;
//
//        }
//        // print the cost graph_map_ for debug
//        std::cout << "Cost Map" << std::endl;
//        for (auto item : cost_map_) {
//            std::cout << "node: " << item.first << ", cost:" << item.second << std::endl;
//
//        }

        // find the path_ from start to end nodes using the parent graph_map_
        int parent;
        int total_cost = cost_map_.at(end_node);
        path_.push_back(end_node);
        while (true) {
            parent = parent_map_.at(end_node);
            path_.push_back(parent);
            end_node = parent;
            if (parent == start_node){
                break;
            }
        }
        return total_cost;
    }

    std::vector<int> get_path(){
        return path_;
    }

private:
    // cost_map_ = the first element is the node and second is the path_ cost from the start_node.
    // parent_map_ = the first element is the child, and the second is the parent
    std::unordered_map<int, int> cost_map_, parent_map_;
    std::vector<int> path_, unvisited_;
    std::unordered_set<int> visited_;

};

class Prim{
public:

    static bool sortbysec(const std::pair<std::pair<int,int>, int> &a,
                   const std::pair<std::pair<int,int>, int> &b)
    {
        return (a.second > b.second);
    }


    // compute the MST of a graph

    int mst(const Graph& g, int start_node) {

        int parent_node = -1;
        int cost = -1;

        // pick a start node and get it's neighbors
        // mark start node as visited
        // sort neighbour nodes by cost and pick the smallest cost
        // mark that node visited.
        // get the neighbors of that node and repeat...
        // until all nodes have been visited

        // CHECK: MST has to have n-1 edges.
        visited_.insert(start_node);
        while(true) {

            // pair(pair(parent node, neighbor node), cost of the edge)
            std::vector<std::pair<std::pair<int, int>, int>> neighbors;
            for (auto item : g.get_neighbors(start_node)) {
                // if node has been visited, don't add it to the neighbors list
                // otherwise infinite loop
                if (!visited_.count(item.first)){
                    neighbors.emplace_back(std::make_pair(start_node, item.first), item.second);
                }

            }

            //sort the neighbor nodes based on the cost in the descending order
            std::sort(neighbors.begin(), neighbors.end(), sortbysec);

            parent_node = neighbors.back().first.first;
            start_node = neighbors.back().first.second;
            cost = neighbors.back().second;
            neighbors.pop_back();
            visited_.insert(start_node);
            total_cost += cost;
            mst_edge_list_.emplace_back(std::make_pair(parent_node, start_node), cost);

            if (visited_.size() == g.get_num_nodes()) {
                break;
            }

        }

        return total_cost;

        }


    [[nodiscard]] std::vector<std::pair<std::pair<int,int>, int> > get_mst_edge_list() const {
        return mst_edge_list_;
    }

    [[nodiscard]] std::unordered_set<int> get_visited() const {
        return visited_;
    }

private:
    //
    int total_cost = 0;
    // <<parent_node, child_node>, cost of the edge>
    std::vector<std::pair<std::pair<int,int>, int> > mst_edge_list_;
    std::unordered_set<int> visited_;
    std::vector<std::unordered_set<int>> connected_components_;
};



int main(){

    // ASSIGNMENT SHORTEST PATH
//    // graph with 20% density
//    Graph g1(50, 1, 10, 0.2);
//    // std::cout << g1;
//
//    // graph with 40% density
//    Graph g2(50, 1, 10, 0.4);
//    // std::cout << g2;
//
//    // compute path_ cost for the g1 over 50 paths from 0 to 1,...,0 to 49
//    // if there is no path_, exclude from the average cost calculation
//    DijstrasShortestPath sp;
//    int total_cost = 0;
//    int temp_cost, count = 0;
//    for (int i = 1; i < g1.get_map().size(); ++i) {
//        temp_cost = sp.shortest_path(g1, 0, i);
//        if (sp.get_path().size() > 1){
//            total_cost += temp_cost;
//            ++count;
//        }
//
//    }
//    std::cout << "Graph 1 average cost over 50 paths is " << static_cast<double>(total_cost) / count << std:: endl;
//
//    // compute path_ cost for the g2 over 50 paths from 0 to 1,...,0 to 49
//    // if there is no path_, exclude from the average cost calculation
//    total_cost = 0;
//    temp_cost = 0, count = 0;
//    for (int i = 1; i < g2.get_map().size(); ++i) {
//        temp_cost = sp.shortest_path(g2, 0, i);
//        if (sp.get_path().size() > 1){
//            total_cost += temp_cost;
//            ++count;
//        }
//
//    }
//    std::cout << "Graph 2 average cost over 50 paths is " << static_cast<double>(total_cost) / count << std:: endl;
//

    // ASSIGNMENT MST
    Graph g("/Users/victoria/CLionProjects/Coursera/DijkstrasAlgorithm/data.txt");


    Prim prim;
    std::cout << "MST cost: " << prim.mst(g, 0) << std::endl;

    std::cout << "Node A, Node B, Edge Cost" << std::endl;
    for(auto item : prim.get_mst_edge_list()){
        std::cout << item.first.first << ", " << item.first.second <<  ", " << item.second << std::endl;
    }


    std::cout << "mst edge list size: " << prim.get_mst_edge_list().size() << std::endl;




    return 0;
}