/* BFS implemented on adjacency matrix representation of graph */


#include <bits/stdc++.h>

using namespace std;

void printArray(int **adj, int m, int n){
    for(int i=0; i<m; i++){
        cout << endl;
        for(int j=0; j<n; j++){
            cout << adj[i][j] << " ";
        }
    }
    cout << endl;
}

int main(){
    int nodes, edges;
    cout << "Please enter the number of nodes!" << endl;
    cin >> nodes;
    cout << "Please enter the number of edges!" << endl;
    cin >> edges;

    int u, v;

    int **adj = new int*[nodes];

    for (int i=0; i<nodes; i++){
        adj[i] = new int[nodes];
    }

    for (int i=0; i<nodes; i++){
        for (int j=0; j<nodes; j++){
            adj[i][j] = 0;
        }
    }

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[1][4] = 1;
    adj[2][5] = 1;
    adj[2][6] = 1;

    printArray(adj, nodes, nodes);

    queue <int> nodes_queue;
    bool visited[nodes];
    for (int i=0; i<nodes; i++){
        visited[i] = false;

    }

    nodes_queue.push(0);
    visited[nodes_queue.front()] = true;
    cout << "Node " << nodes_queue.back() << " visited" << endl;
    while(! nodes_queue.empty()){
        int current_node = nodes_queue.front();
        nodes_queue.pop();
        for(int i=0; i<nodes; ++i){
            if(visited[i] == false && adj[current_node][i] != 0){
                visited[i] = true;
                nodes_queue.push(i);
                cout << "Node " << nodes_queue.back() << " visited" << endl;
            }
        }
    }

}