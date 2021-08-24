#include <bits/stdc++.h>
using namespace std;

// void addEdge(int **adj, int u, int v){
//     adj[u][v] = 1;
// }

void printArray(int **adj, int nodes){
    for(int i=0; i<nodes; i++){
        cout << "Nodes connected to node " << i << endl;
        for(int j=0; j<nodes; j++){
            if(adj[i][j] == 1){
                cout << j << " ";
            }
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

    int v, u;
    int **adj = new int*[nodes];

    for(int i=0; i<nodes; i++){
        adj[i] = new int[nodes];
    }

    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            adj[i][j] = 0;
        }
    }


    // adding the edges to the adjacent matrix
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[1][4] = 1;
    adj[2][5] = 1;
    adj[2][6] = 1;

    printArray(adj, nodes);

    // initiazling a stack for storing viewed nodes
    stack <int> nodeStack;
    bool visited[nodes];
    for(int i=0; i<nodes; i++){
        visited[i] = false;
    }
    nodeStack.push(0);
    visited[0] = true;
    cout << "Node " << 0 << " visited" << endl;
    while(!nodeStack.empty()){
        int currentNode = nodeStack.top();
        nodeStack.pop();
        for(int i=0; i<nodes; i++){
            if(adj[currentNode][i] == 1){
                if(visited[i] == false){
                    visited[i] = true;
                    nodeStack.push(i);
                    cout << "Node " << i << " visited" << endl;
                }
            }
        }
    }
}