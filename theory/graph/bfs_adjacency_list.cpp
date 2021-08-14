/* BFS implementation on adjacency list representation of graph */


#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <int> adj[], int u, int v){
    adj[u].push_back(v);
}

void printArray(vector<int> adj[], int nodes){
    for(int i=0; i<nodes; i++){
        cout << "Edges in node " << i << endl;
        for (auto j: adj[i]){
            cout << adj[i][j] << endl;
        }
    }
}

int main(){
    int nodes, edges;
    cout << "Please enter the number of nodes!" << endl;
    cin >> nodes;
    cout << "Please enter the number of edges!" << endl;
    cin >> edges;

    int u, v;

    vector <int> adj[nodes];
    // for(int i=0; i<edges; i++){
    //     cout << "Please enter the source of " << i << " edge" << endl;
    //     cin >> u;
    //     cout << "Please enter the destination of " << i << " edge" << endl;
    //     cin >> v;
    //     addEdge(adj, u, v);
    // }

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);

    queue <int> node_queue;
    int visited[nodes];
    for (int i=0; i<nodes; i++){
        visited[i] = false;
    }

    node_queue.push(0);
    cout << "Node number " << 0 << " visited" << endl;
    while (! node_queue.empty()){
        int current_node = node_queue.front();
        node_queue.pop();
        for (auto x: adj[current_node]){
            if (visited[x] == false){
                visited[x] = true;
                node_queue.push(x);
                cout << "Node number " << x << " visited" << endl;
            }
        }
    }
}