/*Given a graph where every edge has weight as either 0 or 1. 
A source vertex is also given in the graph. 
Find the shortest path from source vertex to every other vertex.
https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
*/


#include <bits/stdc++.h>
#include <limits>

int infinity = std::numeric_limits<int>::max();

using namespace std;

void addEdge(vector <int> adj_node[], vector <int> adj_weight[], int u, int v, int w){
    adj_node[u].push_back(v);
    adj_node[v].push_back(u);
    adj_weight[u].push_back(w);
    adj_weight[v].push_back(w);
}

void printArray(vector <int> adj[], int nodes){
    for(int i=0; i<nodes; i++){
        cout << "Nodes adjacent to " << i << endl;
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}

int main(){
    int nodes, edges;
    cout << "Please enter the number of nodes!" << endl;
    cin >> nodes;
    cout << "Please enter the number of edges!" << endl;
    cin >> edges;

    vector <int> adj_node[nodes];
    vector <int> adj_weight[nodes];
    addEdge(adj_node, adj_weight, 0, 1, 1);
    addEdge(adj_node, adj_weight, 0, 3, 0);
    addEdge(adj_node, adj_weight, 0, 2, 1);
    addEdge(adj_node, adj_weight, 1, 4, 0);
    addEdge(adj_node, adj_weight, 3, 4, 0);
    addEdge(adj_node, adj_weight, 2, 3, 0);

    printArray(adj_node, nodes);

    deque <int> nodes_queue;
    int distances[nodes];
    for (int i=0; i<nodes; i++){
        distances[i] = infinity;
    }
    nodes_queue.push_back(0);
    distances[0] = 0;
    while(!nodes_queue.empty()){
        int current_node = nodes_queue.front();
        nodes_queue.pop_front();
        for (int i=0; i<adj_node[current_node].size(); i++){
            if (distances[adj_node[current_node][i]] > distances[current_node] + adj_weight[current_node][i]){
                distances[adj_node[current_node][i]] = distances[current_node] + adj_weight[current_node][i];
            
                if (adj_weight[current_node][i] == 0){
                    nodes_queue.push_front(adj_node[current_node][i]);
                }
                else{
                    nodes_queue.push_back(adj_node[current_node][i]);
                }
            }
        }

    }

    for(int i=0; i<nodes; i++){
        cout << distances[i] << " ";
    }
    cout << endl;

    
    
}